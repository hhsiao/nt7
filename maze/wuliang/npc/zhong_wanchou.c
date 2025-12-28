// NPC :zhong_wanchou.c 鍾萬仇 
// By River 98/12
inherit NPC;
void create()
{
        set_name("鍾萬仇", ({ "zhong wanchou", "zhong", "wanchou"}));
        set("title","萬劫谷谷主");
        set("nickname","馬王神");
        set("gender", "男性" );
        set("age", 42);
        set("str", 26);
        set("con", 23);
        set("dex", 22);
        set("int", 10);
        set("per", 5);
   	set("attitude", "heroism");

        set("max_qi", 1800);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 2000);
	set("qi", 1800);	
        set("max_neili", 2000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","只見他好長一張馬臉，眼睛生得甚高，一個園園的大鼻子卻和嘴巴擠在一塊。\n");
        set("combat_exp", 400000);
        set("shen", -1000); 

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("qiantian-yiyang", 100);        
        set_skill("tianlong-xiang", 100);
        set_skill("zhongjia-zhang", 100);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "zhongjia-zhang");
        map_skill("strike", "zhongjia-zhang");
        map_skill("force", "qiantian-yiyang");
        prepare_skill("strike","zhongjia-zhang");

        set("inquiry", ([            
//            "段正淳" : (: ask_duan :),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}