package project.pkg1;

/****************************************
 * Programming by:
 * Nicholas Rebhun
 * Start Date: Feb 10, 2013
 * Last Revision Date: Feb 28, 2013
 ****************************************/

public class SystemTask {

    public String _month;
    public String _message;
    public int _day, _hour, _minute;

    final int hourMax = 23;
    final int hourMin = 0;

    final int minuteMax = 59;
    final int minuteMin = 0;

    final int longMonthDayMax = 31;      //constant int for months with 31 days
    final int shortMonthDayMax = 30;     //constant int for months with 30 days
    final int wMonthDayMax = 28;         //constant int for February
    final static int dayMin = 1;                //minimum number of days in a month

    final int messageCharCountMax = 40;
    final int messageCharCountMin = 0;

    final int dateAbbreviationLimit = 3;

    //////////////////////////////////////////////////
    // Constructors
    //////////////////////////////////////////////////
    public SystemTask(String month, int day, int hour, int minute, String message) {
        setMonth(month);
        setDay(day);
        setHour(hour);
        setMinute(minute);
        setMessage(message);
    }

    public SystemTask() {
        setMonth("Jan");
        setDay(1);
        setHour(1);
        setMinute(1);
        setMessage("Default Values");
    }
    
    //////////////////////////////////////////////////
    // Begin GET Methods
    //////////////////////////////////////////////////
    public String getMonth() {
        return _month;
    }
    public int getDay() {
        return _day;
    }
    public int getHour() {
        return _hour;
    }
    public int getMinute() {
        return _minute;
    }
    public String getMessage() {
        return _message;
    }

    //////////////////////////////////////////////////
    // Begin SET Methods
    //////////////////////////////////////////////////
    public void setMonth(String month){
        boolean monthHasNotBeenSet = true;

        String[] allowedMonths = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        while(monthHasNotBeenSet) {

            while(month.length() != 3) {
                System.out.println("Input must be exactly "+dateAbbreviationLimit+" characters long.");
                month = UserInput.getString(dateAbbreviationLimit, dateAbbreviationLimit);
            }

            for(int i = 0; i < 12; i++){
                if(month.equalsIgnoreCase(allowedMonths[i])){
                    _month = allowedMonths[i];
                    monthHasNotBeenSet = false;
                    break;
                }
            }
            if(monthHasNotBeenSet == true || month == null) {
                System.out.println("That is not a valid month.\nTry again:");
                month = UserInput.getString(dateAbbreviationLimit, dateAbbreviationLimit);
            }
        }
        monthHasNotBeenSet = true;
    }

    public void setDay(int day) {
        boolean dayHasNotBeenSet = true;

        while(dayHasNotBeenSet) {
            if(day >= dayMin && day <= longMonthDayMax){
                _day = day;
                dayHasNotBeenSet = false;
            }
            else {
                System.out.println("Input for day must be between "+dayMin+" and "+longMonthDayMax+".\nTry again:");
                day = UserInput.getInt(dayMin, longMonthDayMax);
            }
        }
        dayHasNotBeenSet = true;
    }

    public void setHour(int hour) {
        boolean hourHasNotBeenSet = true;

        while(hourHasNotBeenSet) {
            if(hour >=  hourMin && hour <= hourMax) {
                _hour = hour;
                hourHasNotBeenSet = false;
            }
            else {
                System.out.println("Input for hour must be between "+hourMin+" and "+hourMax+".\nTry again:");
                hour = UserInput.getInt(hourMin, hourMax);
            }
        }
        hourHasNotBeenSet = true;
    }

    public void setMinute(int minute) {
        boolean minuteHasNotBeenSet = true;

        while(minuteHasNotBeenSet) {

            if(minute >= minuteMin && minute <= minuteMax) {
                _minute = minute;
                minuteHasNotBeenSet = false;
            }
            else {
                System.out.println("That is not a valid minute.");
                minute = UserInput.getInt(minuteMin, minuteMax);
            }
        }
        minuteHasNotBeenSet = true;
    }

    public void setMessage(String message){
        boolean messageHasNotBeenSet = true;

        while(messageHasNotBeenSet) {
            if(message.length() <= messageCharCountMax) {
                _message = message;
                messageHasNotBeenSet = false;
            }
            else {
                System.out.println("Message may be up to "+messageCharCountMax+" characters long.");
                message = UserInput.getString(messageCharCountMin, messageCharCountMax);
            }
        }
        messageHasNotBeenSet = true;
    }

    //////////////////////////////////////////////////
    // Additional Methods
    //////////////////////////////////////////////////
    public String toString() {
        if(_minute < 10){
            return "* "+getMonth()+" "+getDay()+", @ "+getHour()+":0"+getMinute()+"\n* Message: "+getMessage()+"\n*****************************\n";
        }
        else{
            return "* "+getMonth()+" "+getDay()+", @ "+getHour()+":"+getMinute()+"\n* Message: "+getMessage()+"\n*****************************\n";
        }
    }
    
    public void inputSystemTask(){
        System.out.println("Enter the first "+dateAbbreviationLimit+" characters of any month: ");
        String month = UserInput.getString(dateAbbreviationLimit, dateAbbreviationLimit);
        setMonth(month);
        
        System.out.println("Enter a day, between "+dayMin+" and "+longMonthDayMax+": ");
        int day = UserInput.getInt(dayMin, longMonthDayMax);
        setDay(day);
        
        System.out.println("Enter an hour, between "+hourMin+" and "+hourMax+": ");
        int hour = UserInput.getInt(hourMin, hourMax);
        setHour(hour);
        
        System.out.println("Enter a minute, between "+minuteMin+" and "+minuteMax+": ");
        int minute = UserInput.getInt(minuteMin, minuteMax);
        setMinute(minute);
        
        System.out.println("Enter a message, up to "+messageCharCountMax+" characters long, including whitespace: ");
        String message = UserInput.getString(messageCharCountMin, messageCharCountMax);
        setMessage(message);
        
    }
    //////////////////////////////////////////////////
    // Main
    //////////////////////////////////////////////////
    public static void main(String[] args) {
        WorkOrders.Run();      
    }
}