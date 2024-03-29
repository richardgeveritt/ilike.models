/***data***/
Data data()
{
  RandomNumberGenerator rng;
  rng.seed(1);
  size_t n = 100;
  arma::colvec sampled = rnorm(rng,n);
  Data data;
  data["y"] = sampled;
  return data;
}

/***evaluate_log_prior***/
double evaluate_log_prior(const Parameters &parameters)
{
  return dlnorm(parameters["tau"][0], 1.0, 1.0);
}

/***simulate_prior***/
Parameters simulate_prior(RandomNumberGenerator &rng)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

/***evaluate_log_likelihood***/
double evaluate_log_likelihood(const Parameters &parameters, const Data &data)
{
  double precision = parameters["tau"][0];
  return sum(dnorm(data["y"], 0.0, 1.0/sqrt(precision)));
}

/***evaluate_log_importance_proposal***/
double evaluate_log_importance_proposal(const Parameters &parameters)
{
  return dgamma(parameters["tau"][0], 0.1, 0.1);
}

/***simulate_importance_proposal***/
Parameters simulate_importance_proposal(RandomNumberGenerator &rng)
{
  Parameters output;
  output["tau"] = rgamma(rng, 0.1, 0.1);
  return output;
}

/***simulate_mh_proposal***/
Parameters simulate_mh_proposal(RandomNumberGenerator &rng,
                                const Parameters &parameters)
{
  Parameters output;
  output["tau"] = rnorm(rng,parameters["tau"][0],0.001);
  return output;
}

/***evaluate_log_mh_proposal***/
double some_function(const Parameters &proposed_parameters,
                     const Parameters &parameters)
{
  return dnorm(proposed_parameters["tau"][0],parameters["tau"][0],0.001);
}

/***mcmc_weights,c(1)***/

/***mcmc_termination,ilike::iterations(10000)***/

/***smc_sequence,ilike::annealing(power,c(0,p1,1))***/
