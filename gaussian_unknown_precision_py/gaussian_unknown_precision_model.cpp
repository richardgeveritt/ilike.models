/***data,y=my_rnorm(100L)***/

/***evaluate_log_prior,my_dlnorm(parameters.tau,1,1,TRUE)***/

/***simulate_prior,tau=my_rlnorm(1L,1,1)***/

/***evaluate_log_likelihood,sum(my_dnorm(data.y,0,1/sqrt(parameters.tau),TRUE))***/
