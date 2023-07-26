public class Text extends Base implements Non_Playable , Non_Visual{
    public Text(String name , String other_info){
        this.setName(name);
        this.setOther_Info(other_info);
    }
    @Override
    public String getType() {
        return "text";
    }
    @Override
    public void info(){
        System.out.print(getName() + " ");
        System.out.println(getOther_Info());
    }
}

