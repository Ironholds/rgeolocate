#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP rgeolocate_ip_to_df(SEXP);
extern SEXP rgeolocate_ip2location_(SEXP, SEXP, SEXP, SEXP);
extern SEXP rgeolocate_maxmind_(SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"rgeolocate_ip_to_df",     (DL_FUNC) &rgeolocate_ip_to_df,     1},
    {"rgeolocate_ip2location_", (DL_FUNC) &rgeolocate_ip2location_, 4},
    {"rgeolocate_maxmind_",     (DL_FUNC) &rgeolocate_maxmind_,     3},
    {NULL, NULL, 0}
};

void R_init_rgeolocate(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
