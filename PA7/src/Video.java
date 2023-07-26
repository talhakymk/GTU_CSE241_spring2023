public class Video extends Base implements Playable , Visual{
    private String duration;
    @Override
    public String getType() {
        return "video";
    }
    public Video(String name , String duration , String other_info){
        this.setName(name);
        this.setDuration(duration);
        this.setOther_Info(other_info);
    }
    @Override
    public void info(){
        System.out.print(getName() + " ");
        System.out.print(getDuration() + " ");
        System.out.println(getOther_Info());
    }

    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }
}
