public class Base {
    private String Name;
    private String Other_Info;
    private String type;

    public String getType() {
        return type;
    }

    public String getOther_Info() {
        return Other_Info;
    }

    public String getName() {
        return Name;
    }

    public void info() {
        System.out.println(Name);
    }

    public void setName(String name) {
        Name = name;
    }

    public void setOther_Info(String other_Info) {
        Other_Info = other_Info;
    }

}
