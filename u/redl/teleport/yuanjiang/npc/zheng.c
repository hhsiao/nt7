// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit NPC;

int get_help()
{
        write( CYN + query("name") + CYN + "說道：金船裡遺留有廣成子當年所練的金丹，有幾率提高智慧和修為。\n"+ NOR); 
        return 1;
}

int get_help2()
{
        write( CYN + query("name") + CYN + "說道：金蛛乃太古異種，力大無比。如果你有金蛛給我，可以單獨和你合作。\n"+ NOR); 
        return 1;
}

int get_help3()
{
        write( CYN + query("name") + CYN + "說道：天字艙分為“癸壬辛庚己戊丁丙乙甲”十個，持續touch艙門可以從癸推動到甲，艙門前不會自動PK，可以考慮合力加快。\n"+ NOR); 
        return 1;
}

int get_help4()
{
        write( CYN + query("name") + CYN + "說道：金船地圖巨大，用maphere -m比單純的maphere要望得遠些，有特殊出口處必定是艙門所在。\n"+ NOR); 
        return 1;
}

int get_help5()
{
        write( CYN + query("name") + CYN + "說道：元磁力是修煉元磁道術的必需材料，在金船裡使用xi指令可以獲得元磁力，在天字十個艙裡尤其豐富。\n"+ NOR); 
        return 1;
}

int get_help6()
{
        write( CYN + query("name") + CYN + "說道：元磁道術是各種能激發在taoism上的特殊道家武學。比如玄離刀罡可以使你用絕招時多出兩招，小心曉月禪師擅長此道。\n"+ NOR); 
        return 1;
}

int get_help7()
{
        write( CYN + query("name") + CYN + "說道：鐵箱裡的小元磁力爆炸是單獨計算的，能清零你受到的金船大元磁力累積傷害，打開它是件好事。\n"+ NOR); 
        return 1;
}

int get_help8()
{
        write( CYN + query("name") + CYN + "說道：仙隱符葉讓別的玩家和水鬼，都很難發現有你存在的蹤跡，但小心跌倒哦。\n"+ NOR); 
        return 1;
}

int get_reward()
{
                int amount;
        object room, me, obj, *inv;
        me = this_player();
        
        if(me->is_busy()) {
                        write(NOR "你正忙著呢。\n" NOR);
                        return 1;
        }
        me->start_busy(1);

        if( query("online_time", me) < 86400 * 7){
                tell_object(me,CYN + query("name") + CYN + "說道：你在線年齡都沒有超過一週，是小號吧？\n"+ NOR); 
                return 1;
        }      
        
        amount = query("combat_exp", me);
        if( amount < 1000000000){
                tell_object(me,CYN + query("name") + CYN + "說道：你這點點經驗進去能幹什麼？\n"+ NOR); 
                return 1;
        }
        
        if( objectp(query_temp("is_riding", me)) ){//飛行法陣已經限制了背玩家進來，以及很多意外的情況
                tell_object(me,CYN + query("name") + CYN + "說道：下馬先？\n"+ NOR); 
                return 1;
        }      
        
        if( query("weiwang", me) < 1000000){
                tell_object(me,CYN + query("name") + CYN + "說道：你的威望太低了，我只和成名人物合作。\n"+ NOR); 
                return 1;
        }
    
        room = environment(this_object());
        if (query("blv", room) < 9){
                tell_object(me,CYN + query("name") + CYN + "說道：你來得太晚了，打撈已經開始。\n"+ NOR); 
                return 1;
        }
        
      if( query("gcjinchuan_time", me) >= query("gcjinchuan_time", room) ) 
        {
                tell_object(me,CYN + query("name") + "說道：你進出地過於頻繁了！\n"+ NOR); 
                return 1;
       }
        //DEBUG_CHANNEL("player gcjinchuan_time：" + (string)query("gcjinchuan_time", me));
        //DEBUG_CHANNEL("room gcjinchuan_time：" + (string)query("gcjinchuan_time", room));
        
                addn("weiwang", -30000, me);
                tell_object(me, NOR "你被扣除三萬點江湖威望。\n"+ NOR); 
                message_vision(append_color(NOR + CYN + query("name") + CYN + "一揮衣袖，$N" + NOR + CYN + "奮起跳上了元江寶船。\n" + NOR, CYN), me);
                set("gcjinchuan_time", query("gcjinchuan_time", room), me);
                me->move(get_object("/u/redl/teleport/yuanjiang/jiaban"));
                CHANNEL_D->channel_broadcast("rumor", "聽說" + query("name", me) + "已經趕赴元江的廣成金船奪寶。\n");
        return 1;
}      

void create()
{
        set_name( "鄭顛仙" , ({ "zheng dianxian", "zheng" }));
        set("long", @LONG
此乃大熊嶺苦竹庵主人，元江奪寶的倡議者。
LONG);
        set("gender", "女性" );
        set("title", NOR HIC "大顛上人" NOR);
        set("age", 45);
        set("level", 200);
        set("attitude", "friendly");
        set("max_jing", 500000000);
        set("max_qi", 500000000);
        set("max_jingli", 500000000);
        set("jingli", 500000000);
        set("max_neili", 500000000);
        set("neili", 500000000);
        set("jiali", 5000000);
        set("str", 200);
        set("int", 200);
        set("con", 200);
        set("dex", 200);
        set("combat_exp", 120000000000);

        set("inquiry", ([
                "廣成金丹" : (: get_help :),
                "廣成金船" : (: get_reward :),
                "boat" : (: get_reward :),
                "金蛛" : (: get_help2 :),
                "天字艙" : (: get_help3 :),
                "地圖" : (: get_help4 :),
                "元磁力" : (: get_help5 :),
                "元磁道術" : (: get_help6 :),
                "鐵箱" : (: get_help7 :),
                "box" : (: get_help7 :),
                "仙隱符葉" : (: get_help8 :),
                "leaf" : (: get_help8 :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


int push_down(object me)
{
        if (!me) return 1;
        if (!environment(me)) return 1;
        if (environment(me)!=environment(this_object())) return 1;
        
        message_vision(append_color(NOR + CYN + query("name") + CYN + "一揮衣袖，$N" + NOR + CYN + "狼狽地往外面退去。\n" + NOR, CYN), me);
        me->move(query("exits/out", environment(this_object())));
        return 1;
}

void init()
{
        object me = this_player();
        
        //remove_call_out("push_down");
        //call_out("push_down", 60, me);
}


int accept_object(object me, object obj)
{
        object room;
        int *t;
        
        if (me->is_busy())
        {
                tell_object(me, NOR BUSY_MESSAGE NOR); 
                return 0;
        }
        else 
                me->start_busy(2);
                
        if (!query("is jin zhu", obj)){
                tell_object(me, NOR CYN + query("name") + CYN + "搖頭對你說道：我只需要金蛛。\n" NOR); 
                return 0;
    }

/*        if( query("online_time", me) < 86400 * 2){
                tell_object(me,CYN + query("name") + CYN + "說道：你在線年齡都沒有超過兩天，是小號吧？\n"+ NOR); 
                return 0;
        }      */
        
       t = TIME_D->analyse_time(TIME_D->query_real_time());
       if (t[1]>=19 && t[1]<21)
        {
                tell_object(me, NOR CYN + query("name") + "搖頭道：１９～２１點之間不允許私人打撈。\n"+ NOR); 
                return 0;
       }

        room = environment(this_object());
        if (query("blv", room)){
                tell_object(me, NOR CYN + query("name") + CYN + "說道：你來得太晚了，打撈已經開始。\n"+ NOR); 
                return 0;
        }
        
      if( query("gcjinchuan_time", room) && //等於重啟後第一次用金蛛進去的玩家不受這個CD限制
        query("gcjinchuan_time", me) >= query("gcjinchuan_time", room) ) 
        {
                tell_object(me, NOR CYN + query("name") + "說道：你進出地過於頻繁了！\n"+ NOR); 
                return 0;
       }
       
        tell_object(me, NOR CYN + query("name") + CYN + "點頭對你說道：請稍帶片刻。\n" NOR); 

                message_vision(append_color(NOR + CYN + query("name") + CYN + "一揮衣袖，$N" + NOR + CYN + "奮起跳上了元江寶船。\n" + NOR, CYN), me);
                set("gcjinchuan_time", query("gcjinchuan_time", room), me);
                me->move(get_object("/u/redl/teleport/yuanjiang/jiaban"));
        
        room->cdeploy(me);
        return 1;
}



