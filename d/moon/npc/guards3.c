// ken 1999.12.11
inherit NPC;
void create()
{
        set_name("守衛頭領", ({ "guards"}) );
        set("gender", "男性" );
        set("title", "圓月山莊第二代弟子");
        create_family("圓月山莊", 2, "弟子");
        set("class", "moon");
        set("age", 22);
        set("long", "這是圓月山莊莊主丁鵬門下的弟子。\n");
        set("combat_exp", 600000+random(400000));
        set("attitude", "friendly");
        set_skill("unarmed", 150);
	set_skill("moon-steps",random(120)+80);
	set_skill("dodge", random(120)+80);
	set_skill("moon-blade",random(120)+80);
        set_skill("parry",random(120)+80);
        set_skill("blade",random(120)+80);
	map_skill("dodge","moon-steps");
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        set("force",2500);
        set("force_factor",random(40)+20);
        set("max_force",1000);
        set("chat_chance", 3);
        set("chat_msg", ({
                "圓月山莊弟子警惕地注視著四周。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/lblade")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        
}

