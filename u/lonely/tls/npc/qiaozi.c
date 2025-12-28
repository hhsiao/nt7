// 樵子 by leontt

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string axe();
string strike();
void create()
{
        set_name("樵子", ({ "qiao zi", "qiao", "zi" }) );
        set("gender", "男性" );
        set("age", 40);
        set("str", 30);
        set("con", 30);
        set("dex", 25);
        set("int", 25);
        set("per", 20);
        set("attitude", "friendly");

        set("max_qi", 5000);
        set("max_jing", 2800);
        set("eff_jingli", 3600);
        set("neili", 8000);
        set("qi", 5000);
        set("jingli", 3600);
        set("max_neili", 8000);
        set("jiali", 150);
        
        create_family("大理", 13, "弟子");
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("long", 
        "此人左手提著一捆松柴，右手握著一柄斧子，看上去是一個樵夫。\n"+
        "只見他容色豪壯，神態虎虎，舉手邁足間似是大將軍有八面威風，\n"+
        "若非身穿粗布衣裳而在這山間樵柴，必當他是個叱詫風雲的統兵 \n"+
        "元帥。\n");
        
        set("combat_exp", 2300000);
        set("score", 50000);
        set("startroom","/d/tiezhang/road-2"); 

        set("chat_chance_combat", 10);
        set("chat_msg_combat",({
         (: perform_action, "axe.jingtian" :),
         (: exert_function, "qi" :) 
        }));
           
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("axe", 280);
        set_skill("literate", 200);
        set_skill("strike", 280);
        set_skill("qingyan-zhang", 280);
        set_skill("qiantian-yiyang", 280);
        set_skill("pangen-fu", 280);
        set_skill("tianlong-xiang", 280);
        set_skill("finger", 280);
        set_skill("yiyang-zhi", 280);
        set_skill("buddhism", 140);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("axe", "pangen-fu");
        map_skill("force", "qiantian-yiyang");
        map_skill("strike", "qingyan-zhang");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        
        set("inquiry", ([
            "name": "你問這幹什麼? 你來這幹什麼？你和歐陽鋒有什麼關係？",
            "here": "你打死我也不會說的！",
            "基本斧法" : (: axe :),
            
        ]));

        set("chat_chance", 10);
        set("chat_msg", ({
"城池俱壞，英雄安在？雲龍幾度相交代？想興衰，弱為懷。”\n",
"唐家才起隋家敗，事態有如雲變改。疾，也是天地差！遲，也是天地差！”\n",
"天津橋上，憑欄遙望，春陵王氣都凋喪，樹蒼蒼，水茫茫，雲臺不見中興將，千古轉頭歸滅亡。功，也不久長！名，也不久長！”\n",

        }) );
        
        carry_object("/clone/armor/b_cloth")->wear();
        carry_object("/clone/weapon/axe")->wield();
        
        setup();
}

string axe()
{
        mapping fam = this_player()->query("family");
        object ob;        
        if(!fam || fam["family_name"] != "天龍寺")
           return RANK_D->query_respect(this_player())+"與本派素無來往，不知此話從何談起？";
        if(this_player()->query_skill("axe",1) > 100)
           return "你的斧法已經有一定基礎了，這本書對你沒什麼用，還是留給別人吧";        
        ob = unew("/clone/book/axe-book");
        if(!clonep(ob))
           return "你來晚了，我的「基本斧法」已經給別人拿走了。";   
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return "你來晚了，我的「基本斧法」已經給別人拿走了。";  
           }      
        ob->move(this_player());
           return "好吧，這本「基本斧法」就送給你了。";
}

void attempt_apprentice(object ob)
{     
        if( (string)ob->query("gender") == "女性" ){ 
                command ("say 我大理武功需要純陽之體，小姑娘我可不收啊!");
                return;
        }
        if (ob->query("tls")){ 
                command ("say 你已經是天龍寺出家弟子了，我不能再收你了！\n");
                return;
        } 
        if( (int)ob->query_skill("qiantian-yiyang",1) < 150  ){      
                command ("hmm");
                command ("say 你乾天一陽功如此之差，我可不收你?");
                return;
        }
        if(ob->query_str() < 30){
                command("say 要學我的看家本領，必須臂力奇高，依我看" + RANK_D->query_respect(ob) + "的資質似乎不夠？");
                return;
        }
        if ((int)ob->query("job_time/大理") < 300){
                command ("say 我看你為鎮南王府做事做的還不夠啊，努力做吧！");
                return;
        }      
        
        command("say 嗯，看你還是個學武的料，我就收下你吧！");
        command("giggle1");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        ob->set("title","大理第十四代弟子");
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

