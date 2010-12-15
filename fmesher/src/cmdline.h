/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.4
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PACKAGE "fmesher"
#endif

#ifndef CMDLINE_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PACKAGE_NAME "fmesher"
#endif

#ifndef CMDLINE_VERSION
/** @brief the program version */
#define CMDLINE_VERSION "unknown"
#endif

enum enum_io { io_arg_aa = 0 , io_arg_ab, io_arg_ba, io_arg_bb };

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *detailed_help_help; /**< @brief Print help, including all details and hidden options, and exit help description.  */
  const char *full_help_help; /**< @brief Print help, including hidden options, and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * config_arg;	/**< @brief Read options from file.  */
  char * config_orig;	/**< @brief Read options from file original value given at command line.  */
  const char *config_help; /**< @brief Read options from file help description.  */
  char * dump_config_arg;	/**< @brief Dump options to file.  */
  char * dump_config_orig;	/**< @brief Dump options to file original value given at command line.  */
  const char *dump_config_help; /**< @brief Dump options to file help description.  */
  enum enum_io io_arg;	/**< @brief I/O format specification (ascii/binary) (default='bb').  */
  char * io_orig;	/**< @brief I/O format specification (ascii/binary) original value given at command line.  */
  const char *io_help; /**< @brief I/O format specification (ascii/binary) help description.  */
  char ** ic_arg;	/**< @brief Read input as matrix collections in the given files.  */
  char ** ic_orig;	/**< @brief Read input as matrix collections in the given files original value given at command line.  */
  unsigned int ic_min; /**< @brief Read input as matrix collections in the given files's minimum occurreces */
  unsigned int ic_max; /**< @brief Read input as matrix collections in the given files's maximum occurreces */
  const char *ic_help; /**< @brief Read input as matrix collections in the given files help description.  */
  char * oc_arg;	/**< @brief Write output as a matrix collection in the given file.  */
  char * oc_orig;	/**< @brief Write output as a matrix collection in the given file original value given at command line.  */
  const char *oc_help; /**< @brief Write output as a matrix collection in the given file help description.  */
  char ** collect_arg;	/**< @brief Add named matrices to the output collection (default='-').  */
  char ** collect_orig;	/**< @brief Add named matrices to the output collection original value given at command line.  */
  unsigned int collect_min; /**< @brief Add named matrices to the output collection's minimum occurreces */
  unsigned int collect_max; /**< @brief Add named matrices to the output collection's maximum occurreces */
  const char *collect_help; /**< @brief Add named matrices to the output collection help description.  */
  int collect_all_flag;	/**< @brief With --collect=-, load all matrices from the input collections (default=off).  */
  const char *collect_all_help; /**< @brief With --collect=-, load all matrices from the input collections help description.  */
  char ** ir_arg;	/**< @brief Import a raw matrix file in ascii format.  */
  char ** ir_orig;	/**< @brief Import a raw matrix file in ascii format original value given at command line.  */
  unsigned int ir_min; /**< @brief Import a raw matrix file in ascii format's minimum occurreces */
  unsigned int ir_max; /**< @brief Import a raw matrix file in ascii format's maximum occurreces */
  const char *ir_help; /**< @brief Import a raw matrix file in ascii format help description.  */
  char ** input_arg;	/**< @brief Specify triangulation input data, default=s0.  A second name indicates a pre-existing triangulation, as in -Ts0,tv0, further indicates additional data point matrices.  Use - for tv0 to only supply additional points. (default='s0').  */
  char ** input_orig;	/**< @brief Specify triangulation input data, default=s0.  A second name indicates a pre-existing triangulation, as in -Ts0,tv0, further indicates additional data point matrices.  Use - for tv0 to only supply additional points. original value given at command line.  */
  unsigned int input_min; /**< @brief Specify triangulation input data, default=s0.  A second name indicates a pre-existing triangulation, as in -Ts0,tv0, further indicates additional data point matrices.  Use - for tv0 to only supply additional points.'s minimum occurreces */
  unsigned int input_max; /**< @brief Specify triangulation input data, default=s0.  A second name indicates a pre-existing triangulation, as in -Ts0,tv0, further indicates additional data point matrices.  Use - for tv0 to only supply additional points.'s maximum occurreces */
  const char *input_help; /**< @brief Specify triangulation input data, default=s0.  A second name indicates a pre-existing triangulation, as in -Ts0,tv0, further indicates additional data point matrices.  Use - for tv0 to only supply additional points. help description.  */
  double* cet_arg;	/**< @brief Convex encapsulation parameters.  */
  char ** cet_orig;	/**< @brief Convex encapsulation parameters original value given at command line.  */
  unsigned int cet_min; /**< @brief Convex encapsulation parameters's minimum occurreces */
  unsigned int cet_max; /**< @brief Convex encapsulation parameters's maximum occurreces */
  const char *cet_help; /**< @brief Convex encapsulation parameters help description.  */
  double* rcdt_arg;	/**< @brief Generate RCDT, with optional quality parameters (default='21').  */
  char ** rcdt_orig;	/**< @brief Generate RCDT, with optional quality parameters original value given at command line.  */
  unsigned int rcdt_min; /**< @brief Generate RCDT, with optional quality parameters's minimum occurreces */
  unsigned int rcdt_max; /**< @brief Generate RCDT, with optional quality parameters's maximum occurreces */
  const char *rcdt_help; /**< @brief Generate RCDT, with optional quality parameters help description.  */
  char ** quality_arg;	/**< @brief Per vertex RCDT parameters, as one or more one-column matrices with minimum edge lengths for the points specified with -T|--input.  */
  char ** quality_orig;	/**< @brief Per vertex RCDT parameters, as one or more one-column matrices with minimum edge lengths for the points specified with -T|--input original value given at command line.  */
  unsigned int quality_min; /**< @brief Per vertex RCDT parameters, as one or more one-column matrices with minimum edge lengths for the points specified with -T|--input's minimum occurreces */
  unsigned int quality_max; /**< @brief Per vertex RCDT parameters, as one or more one-column matrices with minimum edge lengths for the points specified with -T|--input's maximum occurreces */
  const char *quality_help; /**< @brief Per vertex RCDT parameters, as one or more one-column matrices with minimum edge lengths for the points specified with -T|--input help description.  */
  char ** boundary_arg;	/**< @brief Handle triangulation boundary (default='boundary0').  */
  char ** boundary_orig;	/**< @brief Handle triangulation boundary original value given at command line.  */
  unsigned int boundary_min; /**< @brief Handle triangulation boundary's minimum occurreces */
  unsigned int boundary_max; /**< @brief Handle triangulation boundary's maximum occurreces */
  const char *boundary_help; /**< @brief Handle triangulation boundary help description.  */
  char ** interior_arg;	/**< @brief Handle interior constraints (default='interior0').  */
  char ** interior_orig;	/**< @brief Handle interior constraints original value given at command line.  */
  unsigned int interior_min; /**< @brief Handle interior constraints's minimum occurreces */
  unsigned int interior_max; /**< @brief Handle interior constraints's maximum occurreces */
  const char *interior_help; /**< @brief Handle interior constraints help description.  */
  int fem_arg;	/**< @brief Calculate FEM matrices up through order fem (default='2').  */
  char * fem_orig;	/**< @brief Calculate FEM matrices up through order fem original value given at command line.  */
  const char *fem_help; /**< @brief Calculate FEM matrices up through order fem help description.  */
  int sph0_arg;	/**< @brief Calculate rotationally invariant spherical harmonics up through order sph0 (default='-1').  */
  char * sph0_orig;	/**< @brief Calculate rotationally invariant spherical harmonics up through order sph0 original value given at command line.  */
  const char *sph0_help; /**< @brief Calculate rotationally invariant spherical harmonics up through order sph0 help description.  */
  int sph_arg;	/**< @brief Calculate spherical harmonics up through order sph (default='-1').  */
  char * sph_orig;	/**< @brief Calculate spherical harmonics up through order sph original value given at command line.  */
  const char *sph_help; /**< @brief Calculate spherical harmonics up through order sph help description.  */
  double* bspline_arg;	/**< @brief Calculate rotationally invariant B-spline basis functions.  */
  char ** bspline_orig;	/**< @brief Calculate rotationally invariant B-spline basis functions original value given at command line.  */
  unsigned int bspline_min; /**< @brief Calculate rotationally invariant B-spline basis functions's minimum occurreces */
  unsigned int bspline_max; /**< @brief Calculate rotationally invariant B-spline basis functions's maximum occurreces */
  const char *bspline_help; /**< @brief Calculate rotationally invariant B-spline basis functions help description.  */
  char * points2mesh_arg;	/**< @brief Calculate barycentric triangle coordinates for a set of points (default='s').  */
  char * points2mesh_orig;	/**< @brief Calculate barycentric triangle coordinates for a set of points original value given at command line.  */
  const char *points2mesh_help; /**< @brief Calculate barycentric triangle coordinates for a set of points help description.  */
  double x11_arg;	/**< @brief Show progress in an x11 window, with delay factor (default='1.0').  */
  char * x11_orig;	/**< @brief Show progress in an x11 window, with delay factor original value given at command line.  */
  const char *x11_help; /**< @brief Show progress in an x11 window, with delay factor help description.  */
  double* x11_zoom_arg;	/**< @brief Zoom into a smaller section of the graph, [minx,maxx,miny,maxy].  */
  char ** x11_zoom_orig;	/**< @brief Zoom into a smaller section of the graph, [minx,maxx,miny,maxy] original value given at command line.  */
  unsigned int x11_zoom_min; /**< @brief Zoom into a smaller section of the graph, [minx,maxx,miny,maxy]'s minimum occurreces */
  unsigned int x11_zoom_max; /**< @brief Zoom into a smaller section of the graph, [minx,maxx,miny,maxy]'s maximum occurreces */
  const char *x11_zoom_help; /**< @brief Zoom into a smaller section of the graph, [minx,maxx,miny,maxy] help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int detailed_help_given ;	/**< @brief Whether detailed-help was given.  */
  unsigned int full_help_given ;	/**< @brief Whether full-help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int config_given ;	/**< @brief Whether config was given.  */
  unsigned int dump_config_given ;	/**< @brief Whether dump-config was given.  */
  unsigned int io_given ;	/**< @brief Whether io was given.  */
  unsigned int ic_given ;	/**< @brief Whether ic was given.  */
  unsigned int oc_given ;	/**< @brief Whether oc was given.  */
  unsigned int collect_given ;	/**< @brief Whether collect was given.  */
  unsigned int collect_all_given ;	/**< @brief Whether collect-all was given.  */
  unsigned int ir_given ;	/**< @brief Whether ir was given.  */
  unsigned int input_given ;	/**< @brief Whether input was given.  */
  unsigned int cet_given ;	/**< @brief Whether cet was given.  */
  unsigned int rcdt_given ;	/**< @brief Whether rcdt was given.  */
  unsigned int quality_given ;	/**< @brief Whether quality was given.  */
  unsigned int boundary_given ;	/**< @brief Whether boundary was given.  */
  unsigned int interior_given ;	/**< @brief Whether interior was given.  */
  unsigned int fem_given ;	/**< @brief Whether fem was given.  */
  unsigned int sph0_given ;	/**< @brief Whether sph0 was given.  */
  unsigned int sph_given ;	/**< @brief Whether sph was given.  */
  unsigned int bspline_given ;	/**< @brief Whether bspline was given.  */
  unsigned int points2mesh_given ;	/**< @brief Whether points2mesh was given.  */
  unsigned int x11_given ;	/**< @brief Whether x11 was given.  */
  unsigned int x11_zoom_given ;	/**< @brief Whether x11-zoom was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];
/** @brief all the lines making the full help output (including hidden options) */
extern const char *gengetopt_args_info_full_help[];
/** @brief all the lines making the detailed help output (including hidden options and details) */
extern const char *gengetopt_args_info_detailed_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_ext() instead
 */
int cmdline2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_print_help(void);
/**
 * Print the full help (including hidden options)
 */
void cmdline_print_full_help(void);
/**
 * Print the detailed help (including hidden options and details)
 */
void cmdline_print_detailed_help(void);
/**
 * Print the version
 */
void cmdline_print_version(void);

/**
 * Initializes all the fields a cmdline_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_params_init(struct cmdline_params *params);

/**
 * Allocates dynamically a cmdline_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_params structure
 */
struct cmdline_params *cmdline_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_free (struct gengetopt_args_info *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_config_file() instead
 */
int cmdline_configfile (const char *filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_config_file (const char *filename,
  struct gengetopt_args_info *args_info,
  struct cmdline_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_required (struct gengetopt_args_info *args_info,
  const char *prog_name);

extern const char *cmdline_io_values[];  /**< @brief Possible values for io. */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
