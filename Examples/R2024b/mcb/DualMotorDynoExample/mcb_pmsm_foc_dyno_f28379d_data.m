% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_dyno_f28379d_data.m

% Copyright 2020-2022 The MathWorks, Inc.

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;    			%Hz     // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  	// PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;        	%sec    // Sample time step for controller
Ts_simulink     = T_pwm/2;      	%sec    // Simulation time step for model simulation
Ts_motor        = T_pwm/2;      	%Sec    // Simulation sample time
Ts_inverter     = T_pwm/2;      	%sec    // Simulation time step for average value inverter
Ts_speed        = 10*Ts;        	%Sec    // Sample time for speed controller

%% Set data type for controller & code-gen
% dataType = fixdt(1,32,17);    	% Fixed point code-generation
dataType = 'single';            	% Floating point code-generation

%% System Parameters
% Motor parameters
pmsm_motor1 = mcb_SetPMSMMotorParameters('Teknic2310P');
pmsm_motor1.PositionOffset = 0.0783; % Enter offset values from calibration

pmsm_motor2 = mcb_SetPMSMMotorParameters('Teknic2310P');
pmsm_motor2.PositionOffset = 0.2250; % Enter offset values from calibration

%PRIMO MOTORE TESTATO -> motor2, offset_calcolato=0.2250, originale=0.165
%SECONDO MOTORE TESTATO -> motor1, offset_calcolato=0.0783, originale= 0.165

%% Target & Inverter Parameters
target = mcb_SetProcessorDetails('F28379D',PWM_frequency);
target.comport = '<Select a port...>';
% target.comport = 'COM3';       % Uncomment and update the appropriate serial port

inverter_motor1 = mcb_SetInverterParameters('BOOSTXL-3PhGaNInv');
inverter_motor2 = mcb_SetInverterParameters('BOOSTXL-3PhGaNInv');

% Enable automatic calibration of ADC offset for current measurement
inverter_motor1.ADCOffsetCalibEnable = 1; % Enable: 1, Disable:0
inverter_motor2.ADCOffsetCalibEnable = 1; % Enable: 1, Disable:0

% If automatic ADC offset calibration is disabled, uncomment and update the 
% offset values below manually
% inverter_motor1.CtSensAOffset = 2295;      % ADC Offset for phase current A 
% inverter_motor1.CtSensBOffset = 2286;      % ADC Offset for phase current B
% 
% inverter_motor2.CtSensAOffset = 2295;      % ADC Offset for phase current A 
% inverter_motor2.CtSensBOffset = 2286;      % ADC Offset for phase current B

% Update inverter_motor1.ISenseMax and inverter_motor2.ISenseMaxbased for the 
% chosen motor and target
inverter_motor1 = mcb_updateInverterParameters(pmsm_motor1,inverter_motor1,target);
inverter_motor2 = mcb_updateInverterParameters(pmsm_motor2,inverter_motor2,target);

% Max and min ADC counts for current sense offsets for both inverters
inverter_motor1.CtSensOffsetMax = 2500; 
inverter_motor1.CtSensOffsetMin = 1500;

inverter_motor2.CtSensOffsetMax = 2500;
inverter_motor2.CtSensOffsetMin = 1500;


%% Derive Characteristics
pmsm_motor1.N_base = mcb_getBaseSpeed(pmsm_motor1,inverter_motor1); %rpm // Base speed of motor at given Vdc
pmsm_motor2.N_base = mcb_getBaseSpeed(pmsm_motor2,inverter_motor2); %rpm // Base speed of motor at given Vdc

% mcb_getCharacteristics(pmsm_motor1,inverter_motor1);
% mcb_getCharacteristics(pmsm_motor2,inverter_motor2);

%% PU System details // Set base values for pu conversion

PU_System_motor1 = mcb_SetPUSystem(pmsm_motor1,inverter_motor1);
PU_System_motor2 = mcb_SetPUSystem(pmsm_motor2,inverter_motor2);

%% Controller design // Get ballpark values!
% for motor 1 
%PI_params_motor1 = mcb_SetControllerParameters(pmsm_motor1,inverter_motor1,PU_System_motor1,T_pwm,Ts,Ts_speed);
PI_params_motor1=calculate_PI_params(pmsm_motor1,inverter_motor1);

%Default PI params:
%PI_params_motor1.Kp_speed=0.9089;
%PI_params_motor1.Ti_speed=0.0379;
%PI_params_motor1.Ki_speed=23.9985;

%PI_params_motor1.Kp_i=2.1651;
%PI_params_motor1.Ti_i=0.00052402;
%PI_params_motor1.Ki_i=4121.7;


%Updating delays for simulation
PI_params_motor1.delay_Currents    = 1; %int32(Ts/Ts_simulink);
PI_params_motor1.delay_Position    = 1; %int32(Ts/Ts_simulink);

% mcb_getControlAnalysis(pmsm_motor1,inverter_motor1,PU_System_motor1,PI_params_motor1,Ts,Ts_speed); 

% for motor 2
%PI_params_motor2 = mcb_SetControllerParameters(pmsm_motor2,inverter_motor2,PU_System_motor2,T_pwm,Ts,Ts_speed);
PI_params_motor2=calculate_PI_params(pmsm_motor2,inverter_motor2);

%Default PI params:
%PI_params_motor2.Kp_speed=0.9089;
%PI_params_motor2.Ti_speed=0.0379;
%PI_params_motor2.Ki_speed=23.9985;

%PI_params_motor2.Kp_i=2.1651;
%PI_params_motor2.Ti_i=0.00052402;
%PI_params_motor2.Ki_i=4121.7;

%Updating delays for simulation
PI_params_motor2.delay_Currents    = 1; %int32(Ts/Ts_simulink);
PI_params_motor2.delay_Position    = 1; %int32(Ts/Ts_simulink);

% mcb_getControlAnalysis(pmsm_motor2,inverter_motor2,PU_System_motor2,PI_params_motor2,Ts,Ts_speed); 

%% Displaying model variables
disp(pmsm_motor1);
disp(pmsm_motor2);
disp(inverter_motor1);
disp(inverter_motor2);
disp(target);
disp(PU_System_motor1);
disp(PU_System_motor2);

%% Indici prestazionali

%Indici originali
% IAE = 0.0068
% ISE = 1.6661e-04
% ITAE = 0.0109

%Indici custom
% IAE = 1.1255e-04
% ISE = 0.0045
% ITAE = 0.0112


% [IAE, ISE, ITAE] = computeIndices(error,Ts_speed);
% display(IAE);
% display(ISE);
% display(ITAE);
% 
% function [ISE, IAE, ITAE] = computeIndices(error, Ts)
%     ISE = 0;
%     IAE = 0;
%     ITAE = 0;
% 
%     n = length(error);
% 
%     for k = 1:n
%         t = (k - 1) * Ts;       % Tempo corrente
%         e = error(k);           % Errore corrente
% 
%         ISE = ISE + (e^2) * Ts;
%         IAE = IAE + abs(e) * Ts;
%         ITAE = ITAE + t * abs(e) * Ts;
%     end
% end
