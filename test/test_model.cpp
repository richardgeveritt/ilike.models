// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::depends(ilike, RcppArmadillo, BH, dqrng, sitmo)]]

#include <ilike.h>

using namespace Rcpp;


///////////////////////////////////////////
// Evaluate log prior.                   //
///////////////////////////////////////////

double evaluate_log_prior(const Parameters &inputs)
{
  //sleep(5);
  double output = sum(inputs["theta"]);
  //double output;// sum(inputs.find("theta")->second);
  return output;
}

// [[Rcpp::export]]
XPtr<EvaluateLogDistributionPtr> store_evaluate_log_prior()
{
  return(XPtr<EvaluateLogDistributionPtr>(new EvaluateLogDistributionPtr(&evaluate_log_prior)));
}


///////////////////////////////////////////
// Simulate from prior.                  //
///////////////////////////////////////////

Parameters simulate_prior(rng_ptr rng)
{
  sleep(5);
  Parameters output;
  // arma::colvec my_vec(2, arma::fill::zeros);
  // my_vec[0] = 2.0;
  output["theta"] = simulate_normal(rng, 5.0, 0.1);
  // output["theta"][1] = 6.0;
  // Rcout << my_vec << std::endl;
  // Rcout << output["theta"][1] << std::endl;
  // Rcout << output << std::endl;
  // return output;
  return output;
}

// [[Rcpp::export]]
XPtr<SimulateDistributionPtr> store_simulate_prior()
{
  return(XPtr<SimulateDistributionPtr>(new SimulateDistributionPtr(&simulate_prior)));
}




///////////////////////////////////////////
// Evaluate log likelihood.              //
///////////////////////////////////////////

// // [[Rcpp::export]]
// double evaluate_log_likelihood(const NumericVector &inputs, const NumericMatrix &data)
// {
//   double output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<EvaluateLogLikelihoodPtr> store_evaluate_log_likelihood()
// {
//   return(XPtr<EvaluateLogLikelihoodPtr>(new EvaluateLogLikelihoodPtr(&evaluate_log_likelihood)));
// }



///////////////////////////////////////////
// Simulate from model.                  //
///////////////////////////////////////////

// // [[Rcpp::export]]
// List simulate_model(const NumericVector &inputs, const NumericMatrix &data)
// {
//   List output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<SimulateModelPtr> store_simulate_model()
// {
//   return(XPtr<SimulateModelPtr>(new SimulateModelPtr(&simulate_model)));
// }




















// // [[Rcpp::export]]
// XPtr<SimulateDistributionPtr> store_simulate_importance_proposal()
// {
//   return(XPtr<SimulateDistributionPtr>(new SimulateDistributionPtr(&simulate_importance_proposal)));
// }
