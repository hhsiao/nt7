// ken 1999.12.11
inherit NPC;
void create()
{
	string *order=({"少年", "青年", "中年", "壯年", "老年"});
        set_name((order[random(5)]) +"莊丁", ({ "guards"}) );
        set("gender", "男性" );
        set("title", "圓月山莊");
        set("age", 22);
        set("long", "這是圓月山莊的一個莊丁。\n");
        set("combat_exp", 300000+random(100000));
        set("attitude", "friendly");
        set_skill("unarmed", 50);
	set_skill("moon-steps",random(50)+50);
	set_skill("dodge", random(50)+50);
	set_skill("moon-blade",random(50)+50);
        set_skill("parry",random(50)+50);
        set_skill("blade",random(50)+50);
	map_skill("dodge","moon-steps");
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        set("force",1500);
        set("force_factor",random(30)+10);
        set("max_force",300);
        set("chat_chance", 3);
        set("chat_msg", ({
                "莊丁警惕地喝道；站住！你是幹什麼的？\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/sblade")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        
}

