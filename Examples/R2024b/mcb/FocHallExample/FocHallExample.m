%% Field-Oriented Control of PMSM Using Hall Sensor
% 
% This example implements the field-oriented control (FOC) technique to control 
% the speed of a three-phase permanent magnet synchronous motor (PMSM). The FOC algorithm requires rotor position feedback, which is obtained by a Hall sensor.
% For details about FOC, see
% <docid:mcb_gs#mw_2d6dd8ca-938f-44d3-8334-f5e42bf4b73b Field-Oriented
% Control (FOC)>.
% 
% This example uses the Hall sensor to measure the rotor position. A Hall effect sensor varies its output voltage based on the strength of the applied magnetic field. A PMSM consists of three Hall sensors located electrically 120 degrees apart. A PMSM with this setup can provide six valid combinations of binary states (for example, 001,010,011,100,101, and 110). The sensor provides the angular position of the rotor in the multiples of 60 degrees, which the controller uses to compute the angular velocity. The controller can then use the angular velocity to compute an accurate angular position of the rotor.
% 
% <<../mcb_hall_sensors.png>>
% 

% Copyright 2020 The MathWorks, Inc.

%% Models
% 
% The example includes these models:
% 
% * <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_pmsm_foc_hall_f28069m.slx') mcb_pmsm_foc_hall_f28069m>
% 
% * <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_pmsm_foc_hall_f28379d.slx') mcb_pmsm_foc_hall_f28379d>
% 
% You can use these models for both simulation and code generation.
%%
open_system('mcb_pmsm_foc_hall_f28069m.slx');
%%
% 
% For the model names that you can use for different hardware configurations, see the Required Hardware topic in the Generate Code and Deploy Model to Target Hardware section.
% 
%% Required MathWorks Products
% 
% *To simulate model:*
% 
% *1.* For the model: *mcb_pmsm_foc_hall_f28069m*
% 
% * Motor Control Blockset(TM)
% * Fixed-Point Designer(TM)
% 
% *2.* For the model: *mcb_pmsm_foc_hall_f28379d*
% 
% * Motor Control Blockset(TM)
% 
% *To generate code and deploy model:*
% 
% *1.* For the model: *mcb_pmsm_foc_hall_f28069m*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * C2000(TM) Microcontroller Blockset
% * Fixed-Point Designer(TM)
%
% *2.* For the model: *mcb_pmsm_foc_hall_f28379d*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * C2000(TM) Microcontroller Blockset
% * Fixed-Point Designer(TM) (only needed for optimized code generation)
% 
%% Prerequisites
% 
% *1.* Obtain the motor parameters. 
% We provide default motor parameters with the Simulink(R) model that you can replace with the values from either the motor datasheet or other sources.
% 
% However, if you have the motor control hardware, you can estimate the parameters for the motor that you want to use, by using the Motor Control Blockset parameter estimation tool. For instructions, see
% <docid:mcb_gs#mw_5020c0a3-3cde-4f36-bebc-21090973f8f5 Estimate Motor Parameters by Using Motor Control Blockset Parameter Estimation Tool>.
% 
% The parameter estimation tool updates the _motorParam_ variable (in the MATLAB(R) workspace) with the estimated motor parameters.
% 
% *2.* If you obtain the motor parameters from the datasheet or other sources, update the motor parameters and inverter parameters in the model initialization script
% associated with the Simulink(R) models. For instructions, see <docid:mcb_gs#mw_dd32d1fd-68d8-4cfd-8dea-ef7f7ed008c0 Estimate Control Gains from Motor Parameters>.
% 
% If you use the parameter estimation tool, you can update the inverter parameters, but do not update the motor parameters in the model initialization script. The script automatically extracts motor parameters from the updated _motorParam_ workspace variable.
% 
%% Simulate Model
% 
% This example supports simulation. Follow these steps to simulate the
% model.
% 
% *1.* Open a model included with this example.
% 
% *2.* To simulate the model, click *Run* on the *Simulation* tab.
% 
% *3.* To view and analyze the simulation results, click *Data Inspector* on the *Simulation* tab.
% 
%% Generate Code and Deploy Model to Target Hardware
% This section instructs you to generate code and run the FOC algorithm on
% the target hardware.
% 
% This example uses a host and a target model. The host model is a user interface to the controller hardware board.  You can run the host model on the host computer. The prerequisite to use the host model is to deploy the target model to the controller hardware board. The host model uses serial communication to command the target Simulink(R) model and run the motor in a closed-loop control.
% 
% *Required Hardware*
%
% This example supports these hardware configurations. You can also use the target model name to open the model for the corresponding hardware configuration, from the MATLAB(R) command prompt.
% 
% * F28069M controller card + DRV8312-69M-KIT inverter: <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_pmsm_foc_hall_f28069m.slx') mcb_pmsm_foc_hall_f28069m>
% 
% For connections related to the preceding hardware configuration, see <docid:mcb_gs#mw_5f4d03ef-ffbd-4718-a6c2-499733b1529e Hardware Connections for DRV8312-69M-KIT board>.
% 
% * LAUNCHXL-F28069M controller + BOOSTXL-DRV8305 inverter: <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_pmsm_foc_hall_f28069m.slx') mcb_pmsm_foc_hall_f28069m>
% 
% * LAUNCHXL-F28379D controller + (BOOSTXL-DRV8305 or BOOSTXL-3PHGANINV) inverter: <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_pmsm_foc_hall_f28379d.slx') mcb_pmsm_foc_hall_f28379d>
% 
% For connections related to the preceding hardware configurations, see <docid:mcb_gs#mw_8a869325-5b0d-4631-afd5-05a23622cc5c Hardware Connections for LAUNCHXL board>.
% 
% *Generate Code and Run Model on Target Hardware*
%
% *1.* Simulate the target model and observe the simulation results.
% 
% *2.* Complete the hardware connections.
% 
% *3.* The model automatically computes the Analog-to-Digital Converter (ADC) or current offset values. To disable this functionality (enabled by default), update the value 0 to the variable inverter.ADCOffsetCalibEnable in the model initialization script.
%  
% Alternatively, you can compute the ADC offset values and update it manually in the model initialization scripts. For instructions, see <docid:mcb_gs#mw_2d4f6f28-855c-4e0c-b977-bf5b93a09227 Run 3-Phase AC Motors in Open-Loop Control and Calibrate ADC Offset>.
% 
% *4.* Compute the Hall sensor offset value and update it in the model
% initialization script associated with the target model. For instructions,
% see <docid:mcb_gs#mw_393e50b6-51b7-4443-9ab8-e59cd8d80cc9 Hall Offset
% Calibration for PMSM Motor>.
% 
% *5.* Open the target model for the hardware configuration that you want to use. If you want to change the default hardware configuration settings for the model, see <docid:mcb_gs#mw_3286e9a5-4b65-4b84-9133-a92130b252bc Model Configuration
% Parameters for Sensors>.
%
% *6.* Load a sample program to CPU2 of LAUNCHXL-F28379D, for example,
% program that operates the CPU2 blue LED by using GPIO31 (c28379D_cpu2_blink.slx), to ensure that CPU2 is not mistakenly configured to use the board peripherals intended for CPU1. For more information about the sample program or model, see the Task 2 - Create, Configure and Run the Model for TI Delfino F28379D LaunchPad (Dual Core) section in <docid:c2b_ug#mw_4dc3a55d-e3bc-4773-a16c-67d60b5331bb Getting Started with Texas Instruments C2000 Microcontroller Blockset>.
% 
% *7.* Click *Build, Deploy & Start* on the *Hardware* tab to deploy the model to the hardware.
% 
% *8.* In the target model, click the <matlab:openExample('mcb/FocHallExample','supportingFile','mcb_host_model_f28069m.slx') host model> hyperlink to open the associated host model.
%%
open_system('mcb_host_model_f28069m.slx'); 
%%
% For details about the serial communication between the host and target
% models, see <docid:mcb_gs#mw_7d703f4b-0b29-4ec7-a42b-0b300f580ccc Communication between Host and Target>.
% 
% *9.* In the model initialization script associated with the target model, specify the communication port using the variable _target.comport_. The example uses this variable to update the Port parameter of the Host Serial Setup, Host Serial Receive, and Host Serial Transmit blocks available in the host model.
%  
% *10.* Update the Reference Speed value in the host model.
% 
% *11.* Click *Run* on the *Simulation* tab to run the host model.
% 
% *12.* Change the position of the Start / Stop Motor switch to On, to start running the motor.
% 
% *NOTE:* When you run this example on the hardware at a low Reference Speed, due to a known issue, the PMSM may not follow the low Reference Speed.
% 
% *13.* Observe the debug signals from the RX subsystem, in the Time Scope of host model.
% 
% *NOTE:* If you are using a F28379D based controller, you can also select the debug signals that you want to monitor.
% 