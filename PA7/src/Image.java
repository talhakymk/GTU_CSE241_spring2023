public class Image extends Base implements Visual , Non_Playable{
    private String Dimension_Info;

    @Override
    public String getType() {
        return "image";
    }
    @Override
    public void info(){
        System.out.print(getName() + " ");
        System.out.print(getDimension_Info() + " ");
        System.out.println(getOther_Info());
    }
    public String getDimension_Info() {
        return Dimension_Info;
    }

    public Image(String name , String dimension_info , String other_info){
        this.setName(name);
        this.setDimension_Info(dimension_info);
        this.setOther_Info(other_info);
    }

    public void setDimension_Info(String dimension_Info) {
        Dimension_Info = dimension_Info;
    }
}
