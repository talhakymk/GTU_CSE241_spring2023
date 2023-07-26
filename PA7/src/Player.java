import java.util.ArrayList;
import java.util.List;

public class Player implements Application{
    private List<Base> playList = new ArrayList<>();
    private Base currentlyPlaying;
    private int IndexOfCurrentlyPlaying = 0;
    public List<Base> getPlayList() {
        return playList;
    }

    public int getIndexOfCurrentlyPlaying() {
        return IndexOfCurrentlyPlaying;
    }

    public void setIndexOfCurrentlyPlaying(int indexOfCurrentlyPlaying) {
        IndexOfCurrentlyPlaying = indexOfCurrentlyPlaying;
    }

    public void setPlayList(Base obj) {
        this.playList.add(obj);
    }
    public Base currentlyPlaying(){
        return playList.get(getIndexOfCurrentlyPlaying());
    }

    public void setCurrentlyPlaying(Base currentlyPlaying , int i) {
        this.currentlyPlaying = currentlyPlaying;
        this.IndexOfCurrentlyPlaying = i;
    }

    @Override
    public void showList() {
        if(playList.isEmpty()){
            System.out.println("Playlist is empty");
            return;
        }
        for(int i = 0 ; i < getPlayList().size() ; i++){
            getPlayList().get(i).info();
        }
    }

    @Override
    public void next(String type) {
        for(int i = getIndexOfCurrentlyPlaying() + 1  ; i < getPlayList().size() ; i++){
            if((getPlayList().get(i).getType().equals(type))){
                setCurrentlyPlaying(getPlayList().get(i) , i);
                return;
            }
        }
        System.out.println("There is nothing next same type with that");
    }

    @Override
    public void previous(String type) {
        for(int i = getIndexOfCurrentlyPlaying() - 1 ; i > 0 ; i--){
            if((getPlayList().get(i).getType().equals(type)) ){
                setCurrentlyPlaying(getPlayList().get(i) , i);
                return;
            }
        }
        System.out.println("There is nothing previous same type with that");
    }
    public void emptyPlaylist(){
        playList.clear();
    }
}
