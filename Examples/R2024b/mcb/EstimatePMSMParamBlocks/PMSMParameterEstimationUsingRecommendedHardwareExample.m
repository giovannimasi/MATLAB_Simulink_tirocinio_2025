%% Estimate PMSM Parameters Using Parameter Estimation Blocks
% This example uses the parameter estimation blocks provided by Motor
% Control Blockset(TM) to estimate these parameters of a permanent magnet
% synchronous motor (PMSM) with a quadrature encoder sensor:
% 
% * Phase resistance, _Rs_ (Ohm)
% 
% * D-axis inductance, _Ld_ (Henry)
% 
% * Q-axis inductance, _Lq_ (Henry)
% 
% * Back-EMF constant, _Ke_ (Vpk_LL/krpm, where Vpk_LL is the peak voltage line-to-line measurement)
% 
% * Motor inertia, _J_ (Kg.m^2)
% 
% * Friction constant, _B_ (N.m.s)
% 
% Motor parameter estimation is vital for implementing motor control
% algorithms accurately. Accurate motor parameters enable the algorithm to
% compute the control parameters with precision. Therefore, an accurate
% representation of motor parameters is necessary for a finer speed and
% torque control when you run PMSMs using control techniques such as field-oriented
% control (FOC). Motor parameter estimation also enables you to verify the
% parameter values provided by the motor datasheet. In addition, it enables
% you to accurately replicate the plant model in Simulink(R) using which you
% can simulate real-world scenarios and tests that are difficult to execute
% using a physical hardware setup.
% 
% An accurate simulation helps you reconfigure and run these tests multiple
% times, which can be difficult when you use physical hardware. Therefore,
% these exhaustive tests enable you to predict, find, and fix problems with
% ease including failures that are hard-to-reproduce.
% 
% The example shows you how to use these blocks to design and
% implement a PMSM parameter estimation algorithm on a Texas
% Instruments(TM) hardware board:
% 
% * PMSM Parameter Estimation Configurator
% 
% * PMSM Rs Estimator
% 
% * Ld Estimator
% 
% * Lq Estimator
% 
% * PMSM Mechanical Parameter Estimation
% 
% Alternatively, using this example as a reference, you can utilize these
% blocks to implement a similar algorithm on a different hardware board or configuration.
% 
% The target model included in the example uses the parameter
% estimation blocks in the |mcb_pmsm_param_est_f28379d/Parameter
% Estimation/Param Est| subsystem.
% 
% <<../mcb-pmsm-param-est-blocks.png>>
% 
% These subsystems use the parameter estimation blocks to estimate
% _Rs_, _Ld_, _Lq_, and the mechanical parameters:
% 
% * |RsTest| &mdash; Uses the Rs Estimator block to estimate the motor resistance.
% 
% * |LdTest| &mdash; Uses the Ld Estimator block to estimate _d_-axis inductance.
% 
% * |LqTest| &mdash; Uses the Lq Estimator block to estimate _q_-axis inductance.
% 
% * |MechParam| &mdash; Uses the PMSM Mechanical Parameter Estimation block to estimate the back-EMF constant, motor inertia, and the friction constant.
% 
% If you are only simulating the example, the target model displays the
% estimated parameters. When you deploy the target model to the hardware,
% use the host model to estimate the parameters using the hardware.
% 

% Copyright 2022 The MathWorks, Inc.

%% Model
% The example includes the <matlab:openExample('mcb/PMSMParameterEstimationUsingRecommendedHardwareExample','supportingFile','mcb_pmsm_param_est_f28379d.slx') mcb_pmsm_param_est_f28379d> model.
% 
% You can use the model for both simulation and code generation.
%%
open_system('mcb_pmsm_param_est_f28379d.slx');
%%
% 
% For details about the supported hardware configuration, see Required
% Hardware in the Generate Code and Deploy Model to Target Hardware
% section.
% 
%% Required MathWorks Products
% 
% *To simulate model:*
% 
% * Motor Control Blockset
% 
% * Stateflow(R) (needed only if you modify the example model)
% 
% *To generate code and deploy model:*
% 
% * Motor Control Blockset
% 
% * Embedded Coder(R)
% 
% * C2000(TM) Microcontroller Blockset
% 
% * Stateflow (needed only if you modify the example model)
% 
%% Prerequisite
% 
% Check and update the mandatory motor, inverter, and other system
% parameters listed in the model initialization script <matlab:openExample('mcb/PMSMParameterEstimationUsingRecommendedHardwareExample','supportingFile','mcb_pmsm_param_est_f28379d_data.m') mcb_pmsm_param_est_f28379d_data.m>.
% 
% In addition, you can update the optional motor parameters for simulation.
% 
% You can use the inverter and motor hardware datasheet to determine these
% values.
% 
%% Simulate Model 
% This example supports simulation. Complete these steps to simulate the model.
% 
% *1.* Open the target model included in this example.
% 
% *2.* If required, change the configuration elements for parameter
% estimation, by updating the mask parameters of the PMSM Parameter
% Estimation Configurator block available in the
% |mcb_pmsm_param_est_f28379d/Serial Receive/Variant Subsystem/Sim|
% subsystem. For more details, see <docid:mcb_ref#mw_2b88e2ea-6d35-43cc-9115-ae8517ddaae5 PMSM Parameter Estimation Configurator>.
% 
% *3.* In the *User Controls* section, ensure that the *Parameter Estimation* switch is set to *Stop*.
% 
% *4.* Click *Run* on the *Simulation* tab to simulate the model.
% 
% *5.* Set the *Test Method* switch to either *Manual* or *Auto* mode.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Manual* &mdash;
% This mode enables you to manually execute the tests one by one in the
% prescribed sequence.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Auto* &mdash;
% This mode enables you to automatically run all the tests in the
% prescribed sequence.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If you are using the *Manual* mode:
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *a.* Set the *Test
% Method* switch to *Manual*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *b.* Use the *Test Select* button to select the first test |Rs|.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *c.* Turn the *Parameter Estimation* switch to *Start*. The model runs the
% _Rs_ estimation test after which it displays the computed value in the
% *Estimated Parameters* field.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *d.* Turn the *Parameter Estimation* switch to *Stop*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *e.* Similarly, use the *Test Select* button to select the next test and repeat steps c to e.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *Note:* Ensure that you run all tests in the prescribed sequence of |Rs| &rarr; |Ld| &rarr; |Lq| &rarr; |(Ke, J, B)|. Do not skip any test.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; During simulation, the target model does not support computation of _J_.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If you are using the *Auto* mode:
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *a.* Set the *Test Method* switch to *Auto*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *b.* Turn the
% *Parameter Estimation* switch to *Start*. The model starts running all tests
% in the prescribed sequence of |Rs| &rarr; |Ld| &rarr; |Lq| &rarr; |(Ke, J, B)|, after which it displays the computed parameter values in the *Estimated
% Parameters* field.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *c.* Turn the *Parameter Estimation* switch to *Stop*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *Note:* In the *Auto* mode, the *Test Select* button selection has no effect.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; During simulation, the target model does not support computation of _J_.
% 
%% Generate Code and Deploy Model to Target Hardware
% This section shows you how to generate code and run the parameter
% estimation algorithm on the target hardware to estimate the parameters of the
% connected motor.
% 
% This example uses a host and a target model. The host model is a user
% interface to the controller hardware board. You can run the host model on
% the host computer. To use the host model, first deploy
% the target model to the controller hardware board. The host model uses
% serial communication to command the target to run the parameter
% estimation tests.
% 
% *Required Hardware*
% 
% The example supports this hardware configuration. You can also
% use the target model name to open the model from the MATLAB command
% prompt.
% 
% * LAUNCHXL-F28379D controller + BOOSTXL-DRV8305 inverter: <matlab:openExample('mcb/PMSMParameterEstimationUsingRecommendedHardwareExample','supportingFile','mcb_pmsm_param_est_f28379d.slx') mcb_pmsm_param_est_f28379d>
% 
% For connections related to the hardware configuration, see <docid:mcb_gs#mw_8a869325-5b0d-4631-afd5-05a23622cc5c LAUNCHXL-F28069M and LAUNCHXL-F28379D Configurations>.
% 
% *Generate Code and Run Model on Target Hardware*
% 
% *1.* Complete the hardware connections.
% 
% *2.* The model automatically computes the ADC (or current) offset values.
% To disable this functionality (enabled by default), update the value 0 to
% the variable _inverter.ADCOffsetCalibEnable_ in the model initialization
% script.
% 
% Alternatively, you can compute the ADC offset values and update them
% manually in the model initialization scripts. For instructions, see <docid:mcb_gs#mw_2d4f6f28-855c-4e0c-b977-bf5b93a09227 Run 3-Phase AC Motors in Open-Loop Control and Calibrate ADC Offset>.
% 
% *3.* Compute the quadrature encoder index offset value and update it in the
% model initialization script associated with the target model. For
% instructions, see <docid:mcb_gs#mw_52571b8e-639e-4a24-a8bf-b644eb78edc1
% Quadrature Encoder Offset Calibration for PMSM Motor>.
% 
% *Note:* Verify the number of slits available in the quadrature encoder
% sensor attached to your motor. Check and update the variable
% _pmsm.QEPSlits_ available in the model initialization script. This variable
% corresponds to the *Encoder slits* parameter of the quadrature encoder
% block. For more details about the *Encoder slits* and *Encoder counts per
% slit* parameters, see <docid:mcb_ref#mw_7eb96849-6b42-4571-9c33-e71df0dca95e Quadrature Decoder>.
% 
% *4.* Open the target model. If you want to change the default hardware
% configuration settings for the model, see <docid:mcb_gs#mw_3286e9a5-4b65-4b84-9133-a92130b252bc Model Configuration
% Parameters>.
% 
% *5.* Load a sample program to CPU2 of the LAUNCHXL-F28379D board to ensure that CPU2 is not mistakenly
% configured to use the board peripherals intended for CPU1. For example,
% load the program that operates the CPU2 blue LED by using GPIO31
% (|c28379D_cpu2_blink.slx|). For more information about the sample program or model, see the Task 2 - Create, Configure and Run the Model for TI Delfino F28379D LaunchPad (Dual Core) section in <docid:c2b_ug#mw_4dc3a55d-e3bc-4773-a16c-67d60b5331bb Getting Started with Texas Instruments C2000 Microcontroller Blockset>.
% 
% *6.* Click *Build, Deploy & Start* on the *Hardware* tab to deploy the target
% model to the hardware.
% 
% *7.* Verify that the variables from the target model are available in the MATLAB base workspace.
% 
% *8.* Click the <matlab:openExample('mcb/PMSMParameterEstimationUsingRecommendedHardwareExample','supportingFile','mcb_pmsm_param_est_host_f28379d.slx') host model> hyperlink in the target model to open the
% associated host model.
%%
open_system('mcb_pmsm_param_est_host_f28379d.slx');
%%
% 
% For details about serial communication between the host and target
% models, see <docid:mcb_gs#mw_7d703f4b-0b29-4ec7-a42b-0b300f580ccc Communication between Host and Target>.
% 
% *9.* If required, change the configuration elements for parameter
% estimation, by updating the mask parameters of the PMSM Parameter
% Estimation Configurator block available in the host model. For more
% details, see <docid:mcb_ref#mw_2b88e2ea-6d35-43cc-9115-ae8517ddaae5 PMSM Parameter Estimation Configurator>.
% 
% *10.* In the model initialization script associated with the target
% model, specify the communication port using the variable _target.comport_.
% This variable updates the *Port* parameter of the Host Serial Setup, Host
% Serial Receive, and Host Serial Transmit blocks available in the host
% model.
% 
% *11.* In the *User Controls* section, ensure that the *Parameter
% Estimation* switch is set to *Stop*.
% 
% *12.* Click *Run* on the *Simulation* tab to run the host model. This
% initiates communication between the host model and target hardware.
% 
% *13.* Use the *Test Method* switch to select either *Manual* or *Auto* mode.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Manual* &mdash;
% This mode enables you to manually execute the tests one-by-one in the
% prescribed sequence.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - *Auto* &mdash;
% This mode enables you to automatically run all the tests in the prescribed sequence.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If you are using *Manual* mode:
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *a.* Set the *Test Method* switch to *Manual*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *b.* Use the *Test Select* button to select the first test |Rs|.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *c.* Turn the *Parameter Estimation* switch to *Start*. The model runs the _Rs_ estimation test after which it displays the computed value in the host model.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *d.* Turn the *Parameter Estimation* switch to *Stop*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *e.* Similarly, use the *Test Select* button to select the next test and repeat steps c to e.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *Note:* Ensure that you run all tests in the prescribed sequence of |Rs| &rarr; |Ld| &rarr; |Lq| &rarr; |(Ke, J, B)|. Do not skip any test. The host model
% uses the *Active Test* field to display the test that is currently running.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If you are using *Auto* mode:
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *a.* Set the *Test Method* switch to *Auto*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *b.* Turn the
% *Parameter Estimation* switch to *Start*. The model starts running all
% tests in the prescribed sequence of |Rs| &rarr; |Ld| &rarr; |Lq| &rarr; |(Ke, J, B)| after which it displays the computed parameter values in the
% host model.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *c.* Turn the *Parameter Estimation* switch to *Stop*.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *Note:* In the *Auto* mode, the *Test Select* button selection has no effect.
% 
% &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The host model uses the *Active Test* field to display the test that is currently running.
% 
% *14.* Use the *Debug Signal* combo box to select a debug signal. Monitor
% the selected signal in the scope.
% 
% *Note:* The model can interrupt the currently running test and turn the
% following LEDs red to protect the hardware from the following faults:
% 
% * *Over-current fault* &mdash; This fault occurs when the actual current drawn
% from the power supply is more than the overcurrent limit specified by the
% variables _motor.OverCurrLim_ and _motor.I_rated_ in the model initialization
% script.
% 
% * *Under-voltage fault* &mdash; This fault occurs when input DC voltage drops
% below the undervoltage limit specified by the variables
% _inverter.UnderVoltLim_ and _inverter.V_dc_ in the model initialization
% script.
% 
% After the parameter estimation tests are complete, the host model saves
% the computed parameters in the _motorParam_ variable inside the base
% workspace.
% 