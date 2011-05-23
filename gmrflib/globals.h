
/* globals.h
 * 
 * Copyright (C) 2001-2006 Havard Rue
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
 * RCSId: $Id: globals.h,v 1.46 2010/02/15 08:26:37 hrue Exp $
 *
 */

/*!
  \file globals.h
  \brief Typedefs and defines for \ref globals.c

  This file contains definitions of global variables and other typedefs.

  The random number generator (RNG) used in GMRFLib, need to support the following requirements.

  - A function of type \c GMRFLib_uniform_tp() used to return a Uniform(0,1) variable.
  - A function of type \c GMRFLib_uniform_init_tp() to initialize the RNG
  - A function of type \c GMRFLib_uniform_getstate_tp() which returns in a malloc'ed array the state of the RNG
  - A function of type \c GMRFLib_uniform_setstate_tp() which set the state in the RNG.

  GMRFLib's implementation of this RNG is available in the file \c random.c

*/

#ifndef __GMRFLib_GLOBALS_H__
#define __GMRFLib_GLOBALS_H__

#if !defined(__FreeBSD__)
#include <malloc.h>
#endif
#include <stdlib.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS					       /* empty */
# define __END_DECLS					       /* empty */
#endif

__BEGIN_DECLS
#if !defined(GMRFLib_FALSE)

/*!
  \brief Define GMRFLib_FALSE as (0)
*/
#define GMRFLib_FALSE (0)
#endif
#if !defined(GMRFLib_TRUE)

/*!
  \brief Define GMRFLib_TRUE as (1)
*/
#define GMRFLib_TRUE  (1)
#endif

/*!
  \brief RNG get
*/
typedef double GMRFLib_uniform_tp(void);

/*!
  \brief RNG init
*/
typedef int GMRFLib_uniform_init_tp(unsigned long int seed);

/*!
  \brief RNG getstate
*/
typedef void *GMRFLib_uniform_getstate_tp(void);

/*!
  \brief RNG setstate
*/
typedef int GMRFLib_uniform_setstate_tp(void *state);

/*!
  \brief The CPU timing routine
*/
typedef double GMRFLib_cpu_tp(void);

/* 
   the userfunc's
 */
typedef double *GMRFLib_ai_INLA_userfunc0_tp(GMRFLib_problem_tp * problem, double *theta, int nhyper);
typedef double *GMRFLib_ai_INLA_userfunc1_tp(double *theta, int nhyper, double *covmat);


/* 
   define the global variables, unless __GMRFLib_DONT_DEFINE_GLOBALS is set
 */
#ifndef __GMRFLib_DONT_DEFINE_GLOBALS

extern char GMRFLib_path[];

extern int GMRFLib_blas_level;
extern int GMRFLib_collect_timer_statistics;
extern GMRFLib_smtp_tp GMRFLib_smtp;
extern GMRFLib_reorder_tp GMRFLib_reorder;
extern int GMRFLib_use_wa_table_lookup;
extern int GMRFLib_verify_graph_read_from_disc;

extern gsl_rng *GMRFLib_rng_ptr;

#pragma omp threadprivate(GMRFLib_rng_ptr)

/*!
  \brief Define the function of type GMRFLib_uniform_tp
*/
extern GMRFLib_uniform_tp *GMRFLib_uniform;

/*!
  \brief Hold the pointer to the function of type GMRFLib_init_tp
  \sa random.c
*/
extern GMRFLib_uniform_init_tp *GMRFLib_uniform_init;

/*!
  \brief Hold the pointer to the function of type GMRFLib_getstate_tp
  \sa random.c
*/
extern GMRFLib_uniform_getstate_tp *GMRFLib_uniform_getstate;

/*!
  \brief Hold the pointer to the function of type GMRFLib_setstate_tp
  \sa random.c
*/
extern GMRFLib_uniform_setstate_tp *GMRFLib_uniform_setstate;

/*!
  \brief Hold the pointer to the function of type GMRFLib_cpu_tp
  \sa globals.c
*/
extern GMRFLib_cpu_tp *GMRFLib_cpu;

/*!
  \brief Holds a copy of the (last) seed used to initialise the RNG-routines.
  \sa random.c
*/
extern unsigned long int GMRFLib_rng_seed;

#pragma omp threadprivate(GMRFLib_rng_seed)

/* 
   define types for a user-defined function; compute E_{\theta|y} userfunc
*/

extern GMRFLib_ai_INLA_userfunc0_tp *GMRFLib_ai_INLA_userfunc0;	/* points to the function */
extern int GMRFLib_ai_INLA_userfunc0_dim;		       /* dimension of func() */
extern GMRFLib_density_tp **GMRFLib_ai_INLA_userfunc0_density; /* return the marginal densities here */

extern GMRFLib_ai_INLA_userfunc1_tp *GMRFLib_ai_INLA_userfunc1;	/* points to the function */
extern int GMRFLib_ai_INLA_userfunc1_dim;		       /* dimension of func() */
extern GMRFLib_density_tp **GMRFLib_ai_INLA_userfunc1_density; /* return the marginal densities here */

/* 
   switch for integration type (TRUE/FALSE)
 */
extern int GMRFLib_faster_integration;

/* 
   number of subdivisions for fast_integration
 */
extern int GMRFLib_faster_integration_np;

/* 
   OpenMP spesifics.
 */
extern int GMRFLib_thread_id;
#pragma omp threadprivate(GMRFLib_thread_id)

/*
  Signal USR2: Stop optimiser and present results
*/
extern int GMRFLib_request_optimiser_to_stop;



/* 
   Maximum dimension of bitmap; unlimited if size <= 0
 */
extern int GMRFLib_bitmap_max_dimension;

/* 
   Swap bitmap-file ?
 */
extern int GMRFLib_bitmap_swap;

/* 
   Holds the thread strategy
 */
extern GMRFLib_openmp_tp *GMRFLib_openmp;


/*
  Holds the on/off of meminfo collection
*/
extern int GMRFLib_meminfo_thread_id;
#pragma omp threadprivate(GMRFLib_meminfo_thread_id)

#endif
__END_DECLS
#endif
