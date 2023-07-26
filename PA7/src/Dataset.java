import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Dataset {
    private List<Base> objects = new ArrayList<>();
    private List<Player> players = new ArrayList<>();
    private List<Viewer> viewers = new ArrayList<>();

    public List<Viewer> getViewers() {
        return viewers;
    }

    public void setViewers(List<Viewer> viewers) {
        this.viewers = viewers;
    }

    public List<Player> getPlayers() {
        return players;
    }

    public void setPlayers(List<Player> players) {
        this.players = players;
    }

    public List<Base> getObjects() {
        return objects;
    }

    public void setObjects(List<Base> objects) {
        this.objects = objects;
    }
    public void register(Player player_obj){
        this.players.add(player_obj);
    }
    public void register(Viewer viewer_obj){
        this.viewers.add(viewer_obj);
    }
    public void unregister(Player player_obj){
        this.players.remove(player_obj);
    }
    public void unregister(Viewer viewer_obj){
        this.viewers.remove(viewer_obj);
    }
    public void add(Base obj){
        this.objects.add(obj);
        if(obj.getType().equals("audio") || obj.getType().equals("video")){
            for(int i = 0 ; i < players.size() ; i++){
                players.get(i).setPlayList(obj);
            }
        }
        else {
            for(int i = 0 ; i < viewers.size() ; i++){
                viewers.get(i).setViewList(obj);
            }
        }
    }
    public void remove(Base obj){
        if(objects.isEmpty()){
            System.out.println("There is no object to remove");
            return;
        }
        objects.remove(obj);
        if(obj.getType().equals("audio") || obj.getType().equals("video")){
           for(int i = 0 ; i < players.size() ; i++){
               players.get(i).getPlayList().remove(obj);
           }

        }
        else if(obj.getType().equals("text") || obj.getType().equals("image")){
            for(int i = 0 ; i < viewers.size() ; i++){
                viewers.get(i).getViewList().remove(obj);
            }

        }

    }

}
