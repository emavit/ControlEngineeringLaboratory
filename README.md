# CELAB

IMPORANT - For each lab' folder, we must have parameters of the model, model of the simulation and data get in the lab!!

## FILES DESCRIPTION
* **.slxc** : these files are cache files of the equivalent .slx simulink model; they will not be mentioned in the description.

### ***OLD LABS*** 
contains the material from last year course "Laboratorio di controlli". This material is very similar to the one of "LAB0" (but there are some mistakes)
  * inside there is a folder for each of the 5 labs
      * inside ot these code + data

### ***LAB0***
  * **Black box MAC/Windows** : folders with black box model given to test the real model.
  * **Friction_estimation.mlx** : live script used to estimate viscous and static friction coefficients using data from lab simulations.
  * **Inertia_estimation.mlx** : live script used to estimate the equivalent inertia starting from friction estimastion and lab measurements.
  * **lab0.slx** : Simulink model with the derived motor model, containing all the required reference imput that need to be tested, and all outputs required for plotting.
  * **lab0_deg.slx** : Simulink model with the derived motor model, containing only the [deg] reference step input (basic request for the lab)
  * **lab0_sim.slx** : Simulink model with the black box motor model, containing all the required reference imput that need to be tested, and all outputs required for plotting.
  * **parameters.mat** : workspace file containing the parameters used in the models (saved as the last run of parameters.mlx)
  * **parameters.mlx** : live script containing all the necessary parameters for the models and simulations (including PID constants)

### ***LAB1***
  * **Black box MAC/Windows** : folders with black box model given to test the real model.
  * **parameters.mat** : workspace file containing the parameters used in the models (saved as the last run of parameters.mlx)
  * **Parameters.mlx** : live script containing all the necessary parameters for the models and simulations (including PID constants) - wrt to LABO in this case we are considering the estimated values obtained in LAB
  * **lab1_ss.slx** : Simulink state-space model for nominal tracking of step input
  * **lab1_ss.slx** : Simulinḱ state-space model for robust tracking of step input (nominal model + feedback integrator)
