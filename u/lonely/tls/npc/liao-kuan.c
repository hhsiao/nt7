inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("了寬禪師", ({ "liaokuan chanshi","liaokuan","chanshi"}) );
        set("nickname", "清為尊者");
        set("long", "了寬禪師是本因方丈的第六位弟子，他年約四十，
方面大耳，看起來淳樸憨厚。\n");
        set("gender", "男性" );
        set("class", "bonze");
        set("attitude", "friendly");
        set("age", 41);
        set("shen_type", 1);
        set("str", 25);
        set("int", 22);
        set("con", 23);
        set("dex", 22);
        create_family("天龍寺", 14, "弟子");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 90);
        set_skill("qiantian-yiyang", 100);
        set_skill("dodge", 80);
        set_skill("tianlong-xiang", 80);
        set_skill("parry", 80);
        set_skill("duanjia-jianfa", 100);
        set_skill("strike", 80);
        set_skill("sword", 80);
        set_skill("buddhism", 100);
        set_skill("literate", 80);
        set_skill("qingyan-zhang", 100);
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        map_skill("sword", "duanjia-jianfa");
        map_skill("strike", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");                
        set("inquiry",([
                "百丈橋"  : "百丈橋多年失修，尋常人等不小心就會摔下橋去",
                "後山"  : "過了百丈橋就是後山了，那是歷代高僧潛修之地，尋常人等不得進入",
        ]));
        setup();
        carry_object(BINGQI_D("changjian"))->wield(); 
        carry_object("/d/tls/obj/jiasha1")->wear(); 
        carry_object("/d/tls/obj/sengxie")->wear();
}
#include "liao.h";
