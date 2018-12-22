//mcm.h v1.0
//Definitions for Motor Control Module (MCM)
//Horus
//SEV-CUT-18

extern volatile float current_speed1; //current speed sent by Tritium 1 (for speed control)
extern volatile float current_speed2; //current speed sent by Tritium 2 (for speed control)

//main settings
#define MCM_CAN_BAUDRATE_KBPS			125
#define MCM_MAX_VELOCITY				40	//velocity in m/s that is not reachable
#define MCM_SPEEDCONTROL_MOTOR_CURRENT	0.5	//50% motor current if speed control is enabled

//ADC
#define MCM_RGN_FLOOR				400		//previous value:352 is subtracted from ADC-value to get 0 when not pressed
#define MCM_RGN_DIV					700		//divisor for regenerative brake
#define MCM_THR_FLOOR				450		//previous value:368 is abstracted from ADC-value to get 0 when not pressed
#define MCM_THR_DIV					177		//divisor for throttle
#define MCM_FOOTBRAKE_TRESHOLD		400		//threshold value for footbrake signal

/* Light configuration*/
#define MCM_INDICATOR_TIME			5	//wait 500ms before switching indicators
#define MCM_HEADLIGHTS_NO			0x01
#define MCM_BACKLIGHTS_NO			0x02
#define MCM_INDICATOR_LEFT_NO		0x04
#define MCM_INDICATOR_RIGHT_NO		0x08
#define MCM_HIGH_BEAM_NO			0x10
#define MCM_BRAKELIGHT_NO			0x20
#define MCM_BACKINGLIGHT_NO			0x40
#define MCM_DAYTIMELIGHT_NO			0x80


//Display
#define MCM_DISPLAY_TIME			3	//show page 3s
#define MCM_MAX_PAGE				3	//number of pages that can be displayed

//CAN-configuration
#define MCM_IDENT_MASTER_ID			0x540
#define MCM_DRVCONTROL_MASTER_ID	0x541
#define MCM_BUSCURR_MASTER_ID		0x542
#define MCM_RESET_MASTER_ID			0x543

#define MCM_IDENT_SLAVE_ID			0x580
#define MCM_DRVCONTROL_SLAVE_ID		0x581
#define MCM_BUSCURR_SLAVE_ID		0x582
#define MCM_RESET_SLAVE_ID			0x583

#define MCM_IDM						0x7FF

#define MCM_DEBUG_ID				0x322

#define MCM_STATUS_ID				0x323
#define MCM_LIGHT_ID				0x00A
#define MCM_RELAIS_ID				0x00B

#define MCM_STATUS_INFORMATION		0x441	//for reset after hall error
#define MCM_BUS_MEASUREMENT			0x442	//for start automatic and speed control
#define MCM_SPEED_MEASUREMENT_1		0x443	//for speed control, Tritium 1
#define MCM_CURRENT_MASTER			0x444	//for speed control, Tritium 1
#define MCM_SPEED_MEASUREMENT_2		0x483	//for speed control, Tritium 2


#define MCM_RESET_MASTER_NO			0
#define MCM_BUS_MEASUREMENT_NO		1
#define MCM_BUSCURR_MASTER_NO		2
#define MCM_DRVCONTROL_MASTER_NO	3
#define MCM_BUSCURR_SLAVE_NO		4
#define MCM_DRVCONTROL_SLAVE_NO		5
#define MCM_RELAIS_NO			6
#define MCM_STATUS_NO			7
#define MCM_LIGHT_NO			8
#define MCM_MOTORCURRENT_NO		9



//speed control
#define MCM_SPEED_INCREASE			1.0 / 3.6 //velocity in m/s, that is added when pressing key
#define MCM_SPEED_DECREASE			1.0 / 3.6 //velocity in m/s, that is added when pressing key

//LEDs PORTA
#define MCM_LED_DDR					DDRA
#define MCM_LED_PORT				PORTA

#define MCM_LED_REVERSE				_BV(PA0)
#define MCM_LED_FOOTBRAKE			_BV(PA1)
#define MCM_LED_HANDBRAKE			_BV(PA2)
#define MCM_LED_REG_BRAKE			_BV(PA3)
#define MCM_LED_THROTTLE			_BV(PA4)
#define MCM_LED_SPEED_CONTROL		_BV(PA5)
#define MCM_LED_TRITIUM_ON			_BV(PA6)
#define MCM_LED_TRITIUM_ERROR		_BV(PA7)

#define MCM_ALL_LEDS				(MCM_LED_REVERSE | MCM_LED_FOOTBRAKE | MCM_LED_HANDBRAKE | MCM_LED_REG_BRAKE | MCM_LED_THROTTLE | MCM_LED_SPEED_CONTROL | MCM_LED_TRITIUM_ON | MCM_LED_TRITIUM_ERROR)

//steering wheel keys PORTB
#define MCM_STEERING_WHEEL_DDR		DDRB
#define MCM_STEERING_WHEEL_PORT		PORTB
#define MCM_STEERING_WHEEL_PIN		PINB

#define MCM_INDICATOR_RIGHT			_BV(PB0)
#define MCM_INDICATOR_LEFT			_BV(PB1)
#define MCM_INFO					_BV(PB2)
#define MCM_RADIO					_BV(PB3)
#define MCM_HIGH_BEAM				_BV(PB4)
#define MCM_HORN					_BV(PB5)
#define MCM_SPEED_CONTROL_PLUS		_BV(PB6)
#define MCM_SPEED_CONTROL_MINUS		_BV(PB7)

#define MCM_ALL_STEERING_WHEEL_KEYS (MCM_INDICATOR_RIGHT | MCM_INDICATOR_LEFT | MCM_INFO | MCM_RADIO | MCM_HIGH_BEAM | MCM_HORN | MCM_SPEED_CONTROL_PLUS | MCM_SPEED_CONTROL_MINUS)


//centre console switches PORTC
#define MCM_CENTRE_SWITCHES_DDR		DDRC
#define MCM_CENTRE_SWITCHES_PORT	PORTC
#define MCM_CENTRE_SWITCHES_PIN		PINC

#define MCM_MOTOR_ON				_BV(PC0)
#define MCM_FORWARD					_BV(PC1)
#define MCM_REVERSE					_BV(PC2)
#define MCM_LIGHT_ON				_BV(PC3)
#define MCM_WARNING_LIGHTS			_BV(PC4)
#define MCM_DAYTIME_LIGHTS			_BV(PC5)
#define MCM_SPARE1					_BV(PC6)

#define MCM_ALL_CENTRE_SWITCHES (MCM_MOTOR_ON | MCM_FORWARD | MCM_REVERSE | MCM_LIGHT_ON | MCM_WARNING_LIGHTS | MCM_DAYTIME_LIGHTS)


//MOSFETS and buzzer PORTE
#define MCM_MOSFET_DDR				DDRE
#define MCM_MOSFET_PORT				PORTE
#define MCM_MOSFET_PIN				PINE

#define MCM_MOSFET_TRITIUM1			_BV(PE0)
#define MCM_MOSFET_TRITIUM2			_BV(PE1)
#define MCM_MOSFET_HORN				_BV(PE2)
#define MCM_STARTAUTOMATIC1			_BV(PE3)
#define MCM_BUZZER				    _BV(PE4)
#define MCM_STARTAUTOMATIC2			_BV(PE5)
#define MCM_STARTAUTOMATIC3			_BV(PE6)
#define MCM_STARTAUTOMATIC4			_BV(PE7)

#define MCM_ALL_MOSFETS			(MCM_MOSFET_TRITIUM1 | MCM_MOSFET_TRITIUM2 | MCM_MOSFET_HORN | MCM_STARTAUTOMATIC1 | MCM_BUZZER | MCM_STARTAUTOMATIC2 | MCM_STARTAUTOMATIC3 | MCM_STARTAUTOMATIC4)


//analog inputs PORTF
#define MCM_FOOTBRAKE				PF0
#define MCM_HANDBRAKE				PF1
#define MCM_THROTTLE				PF2
#define MCM_RGN_BRAKE				PF3

//additional inputs/outputs PORTG (PG0-PG4)
#define MCM_SOLAR_DDR				DDRG
#define MCM_SOLAR_PORT				PORTG
#define MCM_SOLAR_PIN				PING

#define MCM_SOLAR_SWITCH			_BV(PG0)
