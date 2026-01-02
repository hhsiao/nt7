// gzf 鬼丈夫

#include <ansi.h>;
inherit NPC;

void create() {
    set_name(HIW "慕容長青" NOR, ({ "jicker" }));
    set("title", HIR "ＰＫ之神" NOR);
    set("gender", "男性");
    set("age", 25);
    set("no_get", 1);
    set("long", sort_msg(HIY"慕容長青，以pk為己任，"
        "一生pk無數，曾與梅山一票人進行PK，從泥潭（二）一直pk到泥潭（三），最終梅山一票人落敗退出泥潭。"
        "與紫雷關係密切，都是喜歡PK類型，一生中遭天神殺檔無數，生命不息，PK不止。\n" NOR));
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
