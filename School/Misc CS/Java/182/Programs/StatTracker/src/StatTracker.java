package stattracker;
/****************************************
 * Programming by:
 * Nicholas Rebhun
 * Start Date: Feb 28, 2013
 * Last Revision Date: Mar 1, 2013
 ****************************************/

public class StatTracker {
    
    private int _kills = 0;
    private int _assists = 0;
    private int _deaths = 0;
            
    private int _rounds = 0;
    public int _drinks = 0;
    
    private String _playerName;
    private int _playerIndex = 0;
    
    private String _gameType;
    
    public Player[] thePlayer = new Player[10];
    
    public StatTracker() {
        
        
    }
    
    //////////////////////////////////////////////////
    // Begin GET Methods
    //////////////////////////////////////////////////
    public String GetName() {
        return _playerName;
    }
    public String GetGameType() {
        return _gameType;
    }

    //////////////////////////////////////////////////
    // Begin GET Methods
    //////////////////////////////////////////////////
    public void SetName(String playerName) {
        System.out.println("Enter new player's name:");
        _playerName = UserInput.getString();
        
    }
    public void SetGameType() {
        System.out.println("Enter the gametype name: ");
        _gameType = UserInput.getString();
    }

    //////////////////////////////////////////////////
    // Additional Methods
    //////////////////////////////////////////////////
    public void createPlayer(int playerIndex) {
        thePlayer[_playerIndex] = new Player(_playerName, _kills, _assists, _deaths, _drinks);
    }
    
    public static void main(String[] args) {
        Player.Run();
    }
}