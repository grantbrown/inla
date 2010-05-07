
/* bitmap.c
 * 
 * Copyright (C) 2004-2006 Havard Rue
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * The author's contact information:
 *
 *       H{\aa}vard Rue
 *       Department of Mathematical Sciences
 *       The Norwegian University of Science and Technology
 *       N-7491 Trondheim, Norway
 *       Voice: +47-7359-3533    URL  : http://www.math.ntnu.no/~hrue  
 *       Fax  : +47-7359-3524    Email: havard.rue@math.ntnu.no
 *
 */

/*!
  \file bitmap.c
  \brief Functions to create bitmaps of precision matrices and Cholesky triangles.

  This file contains functions to create bitmaps (in the  pbm - portable bitmap file format) of
  - the precision matrix (or graph),
  - the reordered precision matrix (or graph)
  - and the Cholesky triangle.

  The main function is \c  GMRFLib_bitmap_problem() which provides a simple interface to create
  a bitmap of the precision matrix, the reordered precision matrix and the Cholesky triangle for
  a given <em> problem </em>.

  \sa GMRFLib_init_problem

  \par Example:
  \verbinclude example-doxygen-bitmap.txt

  which produce the following bitmaps
  \htmlonly
  <table>
  <tr><td align="center">
    <table>
    <tr>
    <td width="250" align="center"><img src="figs/example.gif" width="200" height="200"></td>
    <td width="250" align="center"><img src="figs/example-reordered.gif" width="200" height="200"></td>
    <td width="250" align="center"><img src="figs/example_L.gif" width="200" height="200"></td>
    </tr>
    </table></td></tr>
  </table>
  \endhtmlonly
  showing the precision matrix, the reordered precision matrix and the Cholesky triangle of the reordered precision matrix.

*/

#include <stdio.h>
#if !defined(__FreeBSD__)
#include <malloc.h>
#endif
#include <stdlib.h>

#include "GMRFLib/GMRFLib.h"
#include "GMRFLib/GMRFLibP.h"

#ifndef HGVERSION
#define HGVERSION
#endif
static const char RCSId[] = "file: " __FILE__ "  " HGVERSION;

/* Pre-hg-Id: $Id: bitmap.c,v 1.23 2008/12/28 19:43:43 hrue Exp $ */

int GMRFLib_bitmap_graph__intern(GMRFLib_graph_tp * graph, const char *filename, int *mapping)
{
#define NBitsInByte 8
#define SETBIT(im,jm) { int ii; ii = (im)/NBitsInByte; \
	GMRFLib_setbit(&bitmap[ ii+(jm)*m], (unsigned int) (NBitsInByte-1-((im)-ii*NBitsInByte))); }

	int i, j, im, jm, n = graph->n, m;
	unsigned char *bitmap;
	FILE *fp;
	size_t ret;

	m = n / NBitsInByte;
	if (m * NBitsInByte != n)
		m++;
	bitmap = Calloc(n * m, unsigned char);

	for (i = 0; i < graph->n; i++) {
		im = mapping[i];
		SETBIT(im, im);
		for (j = 0; j < graph->nnbs[i]; j++) {
			jm = mapping[graph->nbs[i][j]];
			SETBIT(im, jm);
		}
	}

	fp = fopen(filename, "w");
	if (fp) {
		fprintf(fp, "P4\n%1d %1d\n", n, n);
		for (i = 0; i < n; i++) {
			ret = fwrite(&bitmap[i * m], (unsigned int) m, 1, fp);
		}
		fclose(fp);
	} else {
		GMRFLib_ERROR(GMRFLib_EOPENFILE);
	}
	Free(bitmap);
	return GMRFLib_SUCCESS;
#undef SETBIT
#undef NBitsInByte
}

/*!
  \brief Create bitmaps of the original and reordered precision matrix (or the graph) in the pbm
  (portable bitmap) file format.

  \param[in] filename_body The body of the filename to store the original and reordered precision
  matrix (or the graph). The files are <em>filename_body</em>.pbm and
  <em>filename_body</em>-reordered.pbm

  \param[in] remap The reordering of the indices, so the new position of node <em>i</em> is
    <em>remap[i]</em>

  \param[in] graph The graph
    
  \remarks If <em>filename_body</em> is \em NULL, then the name \em graph is used.
    
  \remarks Normal usage is to use the \c GMRFLib_bitmap_problem() instead of \c
  GMRFLib_bitmap_graph()
    
  \sa GMRFLib_bitmap_problem
*/
int GMRFLib_bitmap_graph(const char *filename_body, int *remap, GMRFLib_graph_tp * graph)
{
	int i, *mapping;
	char *filename;

	mapping = Calloc(graph->n, int);

	for (i = 0; i < graph->n; i++) {
		mapping[i] = i;
	}

	GMRFLib_EWRAP0(GMRFLib_sprintf(&filename, "%s.pbm", (filename_body ? filename_body : "graph")));
	GMRFLib_EWRAP0(GMRFLib_bitmap_graph__intern(graph, filename, mapping));
	Free(mapping);
	Free(filename);

	if (remap) {
		GMRFLib_EWRAP0(GMRFLib_sprintf(&filename, "%s-reordered.pbm", (filename_body ? filename_body : "graph")));
		GMRFLib_EWRAP0(GMRFLib_bitmap_graph__intern(graph, filename, remap));
		Free(filename);
	}

	return GMRFLib_SUCCESS;
}

/*!  \brief Create bitmaps of the precision matrix (or graph), the reordered precision matrix (or
  graph) and the Cholesky triangle, for a <em>problem</em>

  \param[in] filename_body The body of the filename to store the orignal and reordered precision
  matrix (or the graph). The files are <em>filename_body</em>.pbm,
  <em>filename_body</em>-reordered.pbm and <em>filename_body</em>_L.pbm
  
  \param[in] problem A pointer to the \em problem
  
  \par Example:
  
  The call <tt>GMRFLib_bitmap_problem("Q", problem);</tt> will create the bitmaps <em>Q.pbm</em>,
  <em>Q-reordered.pbm</em> and <em>Q_L.pbm</em>
  
  \sa GMRFLib_init_problem
*/
int GMRFLib_bitmap_problem(const char *filename_body, GMRFLib_problem_tp * problem)
{
	GMRFLib_EWRAP0(GMRFLib_bitmap_graph(filename_body, problem->sub_sm_fact.remap, problem->sub_graph));
	GMRFLib_EWRAP0(GMRFLib_bitmap_factorisation(filename_body, &(problem->sub_sm_fact), problem->sub_graph));

	return GMRFLib_SUCCESS;
}
