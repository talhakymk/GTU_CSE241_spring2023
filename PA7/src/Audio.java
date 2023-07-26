public class Audio extends Base implements Playable , Non_Visual{
    private String duration;

    @Override
    public String getType() {
        return "audio";
    }
    @Override
    public void info(){
        System.out.print(getName() + " ");
        System.out.print(getDuration() + " ");
        System.out.println(getOther_Info());
    }
    public Audio(String name , String duration , String other_info){
        this.setName(name);
        this.setDuration(duration);
        this.setOther_Info(other_info);
    }

    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

}
