// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Dataset ds = new Dataset();
        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));

        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));

        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));

        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));

        System.out.println("info ");
        p1.currentlyPlaying().info();
        System.out.println("removed currently playing of p1");
        ds.remove(p1.currentlyPlaying());
        System.out.println("p1 playlist ");
        p1.showList();
        System.out.println("p2 playlist ");
        p2.showList();
        System.out.println("next audio of p1");
        p1.next("audio");
        p1.currentlyPlaying().info();
        System.out.println("next video of p1");
        p1.next("video");
        p1.currentlyPlaying().info();
        System.out.println("previous audio of p2");
        p2.previous("audio");
        System.out.println("next audio of p2");
        p2.next("audio");
        p2.currentlyPlaying();
        System.out.println("removed currently playing of p2");
        ds.remove(p2.currentlyPlaying());
        System.out.println("playlist of p2");
        p2.showList();
        System.out.println("p1 unregistered");
        ds.unregister(p1);
        System.out.println("removed 2 index of p2");
        ds.remove(p2.getPlayList().get(2));
        System.out.println("p1 playlist");
        p1.showList();
        System.out.println("p2 playlist");
        p2.showList();
        System.out.println("******VIEWER PART******");
        System.out.println("info ");
        v1.currentlyViewing().info();
        System.out.println("removed currently viewing of v1");
        ds.remove(v1.currentlyViewing());
        System.out.println("v1 viewlist ");
        v1.showList();
        System.out.println("p2 viewlist ");
        v2.showList();
        System.out.println("next image of v1");
        v1.next("image");
        v1.currentlyViewing().info();
        System.out.println("next text of v1");
        v1.next("text");
        v1.currentlyViewing().info();
        System.out.println("previous image of v2");
        v2.previous("image");
        System.out.println("next image of v2");
        v2.next("image");
        v2.currentlyViewing();
        System.out.println("removed currently Viewing of p2");
        ds.remove(v2.currentlyViewing());
        System.out.println("viewlist of v2");
        v2.showList();
        System.out.println("v1 unregistered");
        ds.unregister(v1);
        System.out.println("removed 2 index of v2");
        ds.remove(v2.getViewList().get(2));
        System.out.println("v1 viewlist");
        v1.showList();
        System.out.println("v2 viewlist");
        v2.showList();




    }

}