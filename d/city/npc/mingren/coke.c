// gzf 鬼丈夫

#include <ansi.h>;
inherit NPC;

void create() {
    set_name(HIW "渴口" NOR, ({ "coke" }));
    set("title", HIR "幸運之神" NOR);
    set("gender", "男性");
    set("age", 35);
    set("no_get", 1);
    set("long", @LONG
　　　　此人:
　　　　字跡工整，
　　　　文筆極佳，
　　　　才思敏捷，
　　　　過目不忘，
　　　　十年寒窗，
　　　　博學多才，
　　　　見多識廣，
　　　　才高八斗，
　　　　日理萬機，
　　　　明察秋毫，
　　　　英明果斷，
　　　　分身有術，
　　　　孜孜不倦，
　　　　吾等楷模 在下對你的景仰之情有如滔滔長江之水，
　　　　連綿不絕
　　　　……
　　　　又如黃河氾濫，
　　　　一發不可收拾
　　　　……
　　　　嘿嘿
　　　　驚天地！
　　　　泣鬼神！
　　　　感人肺腑！
　　　　感人落淚！
　　　　i 服了 u！

他是泥潭系列有裝備系統從nt3開始到nt7第一個洗出太古的玩家，鴻運當頭，運氣極佳！
LONG );
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
