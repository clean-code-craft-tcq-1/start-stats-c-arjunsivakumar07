extern int emailAlertCallCount;
extern int ledAlertCallCount;

void emailAlerter()
{
	emailAlertCallCount++;
}
void ledAlerter()
{
	ledAlertCallCount++;
}