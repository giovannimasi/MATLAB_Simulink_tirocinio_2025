%% Hall Offset Calibration for PMSM
% This example calculates the offset between the rotor direct axis
% (|d|-axis) and position detected by the Hall sensor. The field-oriented
% control (FOC) algorithm needs this position offset to run the permanent
% magnet synchronous motor (PMSM) correctly. To compute the offset, the
% target model runs the motor in the open-loop condition. The model uses a
% constant ${V_d}$ (voltage along the stator's |d|-axis) and a zero ${V_q}$
% (voltage along the stator's |q|-axis) to run the motor (at a low constant
% speed) by using a position or ramp generator. When the position or ramp
% value reaches zero, the corresponding rotor position is the offset value
% for the Hall sensors.
% 
% The control algorithm (available in the field-oriented control and parameter estimation examples) uses this offset value to compute an accurate position of |d|-axis of the rotor. The controller needs this offset to optimally run the PMSM.
% 

% Copyright 2020 The MathWorks, Inc.

%% Models
% 
% This example includes these models: 
% 
% * <matlab:openExample('mcb/HallOffsetExample','supportingFile','mcb_pmsm_hall_offset_f28069m.slx') mcb_pmsm_hall_offset_f28069m>
% 
% * <matlab:openExample('mcb/HallOffsetExample','supportingFile','mcb_pmsm_hall_offset_f28379d.slx') mcb_pmsm_hall_offset_f28379d>
% 
% You can use these models only for code generation.
%%
open_system('mcb_pmsm_hall_offset_f28069m.slx');
%%
% 
% For the model names that you can use for different hardware configurations, see the Required Hardware topic in the Generate Code and Deploy Model to Target Hardware section.
% 
%% Required MathWorks Products
% 
% *To generate code and deploy model:*
% 
% *1.* For the model: *mcb_pmsm_hall_offset_f28069m*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * C2000(TM) Microcontroller Blockset
% * Fixed-Point Designer(TM)
%
% *2.* For the model: *mcb_pmsm_hall_offset_f28379d*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * C2000(TM) Microcontroller Blockset
% * Fixed-Point Designer(TM) (only needed for optimized code generation)
% 
%% Generate Code and Deploy Model to Target Hardware
% This section instructs you to generate code and run the motor by using open-loop control.
% 
% This example uses a host and a target model. The host model is a user interface to the controller hardware board.  You can run the host model on the host computer. The prerequisite to use the host model is to deploy the target model to the controller hardware board.
% 
% The host model uses serial communication to command the target model and
% run the motor in an open-loop configuration. You can use the host model
% to control the motor rotations and validate direction of rotation of the
% motor. The *Incorrect motor direction* LED in the host model turns red to
% indicate that the motor is running in the opposite direction. When the
% LED turns red, you must reverse the motor phase connections to change the
% direction of rotation. The host model displays the calculated offset
% value.
% 
% *Required Hardware*
%
% This example supports these hardware configurations. You can also use the target model name to open the model for the corresponding hardware configuration, from the MATLAB(R) command prompt.
% 
% * F28069M controller card + DRV8312-69M-KIT inverter: <matlab:openExample('mcb/HallOffsetExample','supportingFile','mcb_pmsm_hall_offset_f28069m.slx') mcb_pmsm_hall_offset_f28069m>
% 
% For connections related to the preceding hardware configuration, see <docid:mcb_gs#mw_5f4d03ef-ffbd-4718-a6c2-499733b1529e Hardware Connections for DRV8312-69M-KIT board>.
% 
% * LAUNCHXL-F28379D controller + (BOOSTXL-DRV8305 or BOOSTXL-3PHGANINV) inverter: <matlab:openExample('mcb/HallOffsetExample','supportingFile','mcb_pmsm_hall_offset_f28379d.slx') mcb_pmsm_hall_offset_f28379d>
% 
% To configure the model *mcb_pmsm_hall_offset_f28379d*, set the *Inverter Enable Logic* field (in the *Configuration* panel of target model) to:
% 
% * *Active High*: To use the model with BOOSTXL-DRV8305 inverter.
% * *Active Low*: To use the model with BOOSTXL-3PHGANINV inverter.
% 
% For connections related to the preceding hardware configuration, see <docid:mcb_gs#mw_8a869325-5b0d-4631-afd5-05a23622cc5c Hardware Connections for LAUNCHXL board>.
% 
% *Generate Code and Run Model on Target Hardware*
%
% *1.* Complete the hardware connections.
% 
% *2.* Open the target model for the hardware configuration that you want to use. If you want to change the default hardware configuration settings for the target model, see <docid:mcb_gs#mw_3286e9a5-4b65-4b84-9133-a92130b252bc Model Configuration
% Parameters for Sensors>.
% 
% *3.* Update the motor parameters in the *Configuration* panel of the
% target model.
% 
% * *Number of Pole Pairs*
% * *PWM Frequency [Hz]*
% * *Data type for control algorithm*
% * *Vd Ref in Per Unit voltage*
% 
% *4.* Load a sample program to CPU2 of LAUNCHXL-F28379D, for example,
% program that operates the CPU2 blue LED by using GPIO31 (c28379D_cpu2_blink.slx), to ensure that CPU2 is not mistakenly configured to use the board peripherals intended for CPU1. For more information about the sample program or model, see the Task 2 - Create, Configure and Run the Model for TI Delfino F28379D LaunchPad (Dual Core) section in <docid:c2b_ug#mw_4dc3a55d-e3bc-4773-a16c-67d60b5331bb Getting Started with Texas Instruments C2000 Microcontroller Blockset>.
% 
% *5.* Click *Build, Deploy & Start* on the *Hardware* tab to deploy the target model to the hardware.
% 
% *6.* Click the <matlab:openExample('mcb/HallOffsetExample','supportingFile','mcb_pmsm_host_offsetComputation_f28069m.slx') host model> hyperlink in the target model to open the associated host model.
%%
open_system('mcb_pmsm_host_offsetComputation_f28069m.slx'); 
%%
% For details about the serial communication between the host and target
% models, see <docid:mcb_gs#mw_7d703f4b-0b29-4ec7-a42b-0b300f580ccc Communication between Host and Target>.
% 
% You can use the Scope in the host model to monitor the rotor position and offset values.
% 
% *7.* In the host model, open the blocks Host Serial Setup, Host Serial Receive, and Host Serial Transmit, and select a *Port*.
% 
% *8.* Click *Run* on the *Simulation* tab to run the host model. The motor
% runs and calibration begins when you start simulation. After the calibration
% process is complete, simulation ends and the motor stops automatically.
% 
% *9.* See the *Calibration Status* section to know the status of the calibration
% process:
% 
% * The *Calibration in progress* LED turns orange when the motor starts
% running. Notice the rotor position and the variation in the offset value in the
% Scope (the position signal indicates a ramp signal with an
% amplitude between 0 and 1). After the calibration process is complete, the LED turns
% grey.
% 
% * The *Calibration complete* LED turns green when the calibration process is complete. Then
% the |Calibration Output| field displays the computed offset value.
% 
% * The *Incorrect motor direction* LED turns red if the motor runs in the
% opposite direction. Then the |Calibration Output| field displays the value "NaN." Turn
% off the DC power supply (24V) and reverse the motor phase connections
% from ABC to CBA. Repeat steps 5 to 8 and check if the Calibration complete LED is
% green. Verify that the |Calibration Output| field displays the offset
% value.
% 
% *Note*: To immediately stop the motor, click the *Emergency Motor Stop* button.
% 
% This example does not support simulation. The example automatically saves the computed
% offset value in the |PositionOffset| variable available in the base workspace.
% 
% For examples that implement FOC using a Hall sensor, update the computed offset in the |pmsm.PositionOffset| parameter in the model initialization script linked to the example. For instructions, see <docid:mcb_gs#mw_dd32d1fd-68d8-4cfd-8dea-ef7f7ed008c0 Estimate Control Gains from Motor Parameters>.
% 