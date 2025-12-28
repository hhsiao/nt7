// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>

inherit NPC;

int get_reward()
{
                int amount;
        object me, obj;
        me = this_player();
        
        if( query("online_time", me) < 3600){
                tell_object(me,CYN + query("name") + "深情地看了你一眼說：你在線時間還沒有超過一小時吧？\n"+ NOR); 
                return 1;
        }      
        amount = query("active", me);
        if( amount < 1){
                tell_object(me,CYN + query("name") + "面孔扭曲地說：你至少也要有1點活躍度才能來我這兌換呀！\n"+ NOR); 
                return 1;
        }
        if( time() - query("active_endtime", me) < 3600){
                tell_object(me,CYN + query("name") + "摳了摳鼻孔，慢悠悠地說：活躍度每小時兌換一次！\n"+ NOR); 
                return 1;
        }
        
        if (amount > 100) amount=100;
        addn("active", -amount, me);
        
                if( query("online_time", me) < 86400) obj = new(__DIR__"obj/xianghy");//一天以內的新玩家，可以抽到天賦丹和低級rune
                else obj = new(__DIR__"obj/xianghy2");//一天以上的老玩家可以抽到中高級rune
                
                obj->set_amount(amount);
        message_vision(YEL + query("name") + NOR + YEL+ "拿出"+chinese_number(amount)+"個箱子交給"+ NOR +"$N"+ NOR + YEL+"。\n" + NOR, me);        
        obj->move(me);
        set("active_endtime", time(), me);
        return 1;
}      

void create()
{
        set_name(NOR "小常子" NOR, ({ "xiao changzi", "xiao", "changzi" }));
         set("nickname", YEL "聊天室夥計" NOR);
        set("long", @LONG
泥潭撿大糞先行者，金盆洗手後在公共聊天室端茶遞水。
LONG);
        set("gender", "男性" );
        set("age", 30);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 1200000);

        set("inquiry", ([
                        "獎池" : (: call_other("/u/redl/obj/cigarette_c", "ask_pond", query("name") ) :) ,
                "寶箱" : (: get_reward :),
                "活躍度" : (: get_reward :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


