// gzf 鬼丈夫

#include <ansi.h>;
inherit NPC;

void create() {
    set_name(HIW "蒼狼" NOR, ({ "feel" }));
    set("title", HIR "失落之神" NOR);
    set("gender", "男性");
    set("age", 35);
    set("no_get", 1);
    set("long", sort_msg(HIY"自泥潭一開站之日便有蒼狼的存在，開創叱吒風雲的雪域蒼狼一派，一時驚天地泣鬼神，然後在雪域蒼狼"
        "與大俠紅豆,raken,紫雷幫派一戰後，都歸隱江湖。此戰勝負無人知曉。自此不再有蒼狼身影。自泥潭一後雖有傳聞有蒼狼出現，但輝煌不再。\n" NOR));
    set("combat_exp", 60000);
    set("shen_type", 1);
    set("attitude", "friendly");

    set("apply/attack", 50);
    set("apply/defense", 50);

    set("max_qi", 800);
    set("max_jing", 800);
    set("max_neili", 800);

    setup();

    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
