#include<IterativeRobot.h>
#include<Joystick.h>
#include<RobotDrive.h>
#include<ctrlib/CANTalon.h>

const int joystickNum = 0;
const int rMotorNum = 2;
const int lMotorNum = 6;

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {

	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override {
		myRobot.Drive(0.0, 0.0);
	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {
		myRobot.Drive(0.0, 0.0);
	}

	void TeleopPeriodic() {
		myRobot.ArcadeDrive(stick);
	}

	void TestPeriodic() {

	}

private:
	CANTalon *rMotor = new CANTalon(rMotorNum);
	CANTalon *lMotor = new CANTalon(lMotorNum);
	frc::RobotDrive myRobot {lMotor, rMotor};
	frc::Joystick stick{joystickNum};
};

START_ROBOT_CLASS(Robot)
