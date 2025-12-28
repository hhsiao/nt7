inherit F_MASTER;
inherit NPC;
string ask_me();
void create()
{
        set_name("了修禪師", ({ "liaoxiu chanshi","liaoxiu","chanshi"}) );
        set("nickname", "天眼尊者");
        set("long", "了修禪師是本因方丈的第三位弟子，他身材高大，
四肢修長，武藝、佛學均十分了得。\n");
        set("gender", "男性" );
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 24);
        set("dex", 24);
        create_family("天龍寺", 14, "弟子");
        set("inquiry",([
                "指法訣要" : (: ask_me :),
        ]));

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1500);
        set("eff_jingli", 1500);
        set("max_jing", 1500);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 10000);
        set_skill("strike", 120);
        set_skill("force", 120);
        set_skill("qiantian-yiyang", 120);
        set_skill("dodge", 120);
        set_skill("qingyan-zhang", 120);
        set_skill("tianlong-xiang", 120);
        set_skill("parry", 120);
        set_skill("finger", 120);
        set_skill("sword", 120);
        set_skill("yiyang-zhi", 120);
        set_skill("buddhism", 120);
        set_skill("literate", 100);
        map_skill("strike", "qingyan-zhang");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        set("book_count", 1);   
        setup();
        carry_object("/d/tls/obj/jiasha1")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}
string ask_me()
{
        mapping fam = this_player()->query("family");
        object ob;
        
        if(!fam || fam["family_name"] != "天龍寺")
           return RANK_D->query_respect(this_player())+"與本寺素無來往，不知此話從何談起？";
         if(this_player()->query_skill("finger",1) > 30)
           return "你的指法已經有一定基礎了，這本書對你沒什麼用，還是留給別的弟子吧";
		if(query("book_count") < 1)
           return "你來晚了，本派的《指法訣要》不在此處。";
        add("book_count", -1);
        ob = new("/d/tls/obj/zhifa");
        ob->move(this_player());
        return "好吧，這本「指法訣要」你拿回去好好鑽研。";
}
#include "liao.h";
