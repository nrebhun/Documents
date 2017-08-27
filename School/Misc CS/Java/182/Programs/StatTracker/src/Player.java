package stattracker;
/****************************************
 * Programming by:
 * Nicholas Rebhun
 * Start Date: Feb 28, 2013
 * Last Revision Date: Mar, 1, 2013
 ****************************************/

public class Player {
    
    final int minPoints = 0, maxPoints = 50;
    
    private int _kills;
    private int _assists;
    private int _deaths;

    private int _rounds;
    private int _drinks;
    
    private int _playerIndex;
    
    
    public Player() {
        String playerName = "default";
        int kills = 0;
        int assists = 0;
        int deaths = 0;
        int drinks = 0;
    }
    
    public Player(String playerName, int kills, int assists, int deaths, int drinks) {
        
    }
    
    public void AddKills() {
        System.out.println("How many kills were earned, this game?");
        _kills =  + UserInput.getInt(minPoints, maxPoints);
    }
    public void AddAssists() {
        System.out.println("How many assists were earned, this game?");
        _assists = _assists + UserInput.getInt(minPoints, maxPoints);
    }
    public void AddDeaths() {
        System.out.println("How many deaths occurred, this game?");
        _deaths = _deaths + UserInput.getInt(minPoints, maxPoints);
    }    
    public void AddDrink() {
        _drinks++;
    }
    public void AddRound() {
        _rounds++;
    }

    public static void Run() {
        Player thePlayer = new Player();
 
        char choice = 'z';

        do {
            System.out.println("/----------------------------------\\");
            System.out.println("|     Welcome to Stat Tracker!     |");
            System.out.println("|Please select from the following: |");
            System.out.println("|----------------------------------|");
            System.out.println("|K  ................... Add Kills  |");
            System.out.println("|A  ................... Add Assists|");
            System.out.println("|D  ................... Add Deaths |");
            System.out.println("|B  ................... Add Drink  |");
            System.out.println("|R  ................... Add Rounds |");
            System.out.println("|E  ................... Exit       |");
            System.out.println("\\----------------------------------/");

            choice = UserInput.getChar();

            switch (Character.toLowerCase(choice)) {
                case 'k' :
                    thePlayer.AddKills();
                    System.out.println("You added kills!");
                    break;

                case 'a' :
                    thePlayer.AddAssists();
                    System.out.println("You added deaths.");
                    break;

                case 'd' :
                    thePlayer.AddDeaths();
                    System.out.println("You added assists!");
                    break;
                    
                case 'b' :
                    thePlayer.AddDrink();
                    System.out.println("You added a drink!");
                    break;

                case 'r' :
                    thePlayer.AddRound();
                    System.out.println("You added a round");
                    break;

                default :
                    System.out.println("That is not valid input. Please Try again.");
                    break;
            }
        } while (choice != 'e');
    }
}
