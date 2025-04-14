% Model         :   PMSM parameter estimation
% Description   :   Set Parameters for PMSM Parameter estimation
% File name     :   mcb_pmsm_param_est_f28379d_data.m

% Copyright 2022 The MathWorks, Inc.

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;             %Hz     // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s      // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;            %sec    // Sample time for control system
Ts_simulink     = T_pwm/2;          %sec    // Simulation time step for model simulation
Ts_motor        = T_pwm/2;          %Sec    // Simulation time step for pmsm
Ts_inverter     = T_pwm/2;          %sec    // Simulation time step for inverter
%% Set data type for controller & code-gen
dataType = 'single';                % Floating point code-generation

%% System Parameters 
% Mandatory motor parameters
motor.p = 4;
motor.I_rated = 7.1;
motor.QEPSlits = 1000;
motor.N_rated = 4000;
motor.PositionOffset = 0.1735;      % Per-Unit position offset
motor.OverCurrLim = 1.5;            % Overcurrent limit as a ratio of motor rated current

% Optional motor parameters (required only for simulation)
motor.Rs = 0.36;
motor.Ld = 0.2e-3;
motor.Lq = 0.2e-3;
motor.Ke = 4.64;
motor.FluxPM   = (motor.Ke)/(sqrt(3)*2*pi*1000*motor.p/60);
motor.J = 7.06155e-6;
motor.B = 2.63687e-6;

%% Target & Inverter Parameters
target = mcb_SetProcessorDetails('F28379D',PWM_frequency);
target.SCI_baud_rate    = 12e6;  	% Set baud rate for serial communication
target.ADCCalibEnable   = 1;     	% Enable : 1, Disable :0 to Auto-calibrate ADCs
target.comport = '<Select a port...>';
% target.comport = 'COM3';       	% Uncomment and update the appropriate serial port
                                  
inverter = mcb_SetInverterParameters('BoostXL-DRV8305');
inverter.UnderVoltLim = 0.8;     	% Undervoltage limit as a ratio of inverter.V_dc

% Enable automatic calibration of ADC offset for current measurement
inverter.ADCOffsetCalibEnable = 1;  % Enable: 1, Disable:0 

% If automatic ADC offset calibration is disabled, uncomment and update the 
% offset values below manually
% inverter.CtSensAOffset = 2295;    % ADC Offset for phase current A 
% inverter.CtSensBOffset = 2286;    % ADC Offset for phase current B

% Update inverter.ISenseMax based for the chosen motor and target
inverter = mcb_updateInverterParameters(motor,inverter,target);

% Max and min ADC counts for current sense offsets
inverter.CtSensOffsetMax = 2500;    % Maximum permitted ADC counts for current sense offset
inverter.CtSensOffsetMin = 1500;    % Minimum permitted ADC counts for current sense offset