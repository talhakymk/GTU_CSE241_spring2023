import java.util.ArrayList;
import java.util.List;

public class Viewer implements Application{
    private List<Base> viewList = new ArrayList<>();
    private Base currentlyViewing;
    private int IndexOfCurrentlyViewing = 0;
    public List<Base> getViewList() {
        return viewList;
    }

    public int getIndexOfCurrentlyViewing() {
        return IndexOfCurrentlyViewing;
    }

    public void setIndexOfCurrentlyViewing(int indexOfCurrentlyViewing) {
        IndexOfCurrentlyViewing = indexOfCurrentlyViewing;
    }

    public void setViewList(Base obj) {
        this.viewList.add(obj);
    }
    public Base currentlyViewing(){
        return viewList.get(getIndexOfCurrentlyViewing());
    }

    public void setCurrentlyViewing(Base currentlyViewing , int i) {
        this.currentlyViewing = currentlyViewing;
        this.IndexOfCurrentlyViewing = i;
    }

    @Override
    public void showList() {
        if(viewList.isEmpty()){
            System.out.println("Viewlist is empty");
            return;
        }
        for(int i = 0 ; i < getViewList().size() ; i++){
            getViewList().get(i).info();
        }
    }

    @Override
    public void next(String type) {
        for(int i = getIndexOfCurrentlyViewing()+1 ; i < getViewList().size() ; i++){
            if((getViewList().get(i).getType().equals(type)) ){
                setCurrentlyViewing(getViewList().get(i) , i);
                return;
            }
        }
        System.out.println("There is nothing next same type with that");
    }

    @Override
    public void previous(String type) {
        for(int i = getIndexOfCurrentlyViewing()-1 ; i > 0 ; i--){
            if((getViewList().get(i).getType().equals(type))){
                setCurrentlyViewing(getViewList().get(i) , i);
                return;
            }
        }
        System.out.println("There is nothing previous same type with that");
    }
    public void emptyViewlist(){
        viewList.clear();
    }
}
