#include <ansi.h>
#include <command.h>

inherit NPC;

void greeting(object ob);
void remove_ct(object ob);

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "這位店小二正笑咪咪地忙著，還不時拿起掛在脖子上的抹布擦臉。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        setup();
        if (clonep()) keep_heart_beat();
}

string accept_ask(object me, string topic)
{
        switch (random(5))
        {
        case 0:
                return "嗨！我忙著呢，你和我那醉仙樓做活的兄弟聊聊吧！";

        case 1:
                return "你幹啥？沒看我忙著呢麼？";

        case 2:
                return "哎呀呀，你沒看我忙著呢麼，要打聽消息你去找我醉仙樓做活的兄弟吧？";

        case 3:
                return "春來茶館的老闆娘阿慶嫂消息也靈通，那些爺們什麼都告訴她，要不你問她去？";

        default:
               return "我那醉仙樓做活的兄弟消息才叫靈通，你去和他聊吧。";
        }
}

void init()
{       
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 5, ob);
                call_out("remove_ct", 3, ob);
        }
}

void remove_ct(object ob)
{
        remove_call_out("greeting");
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment() ) return;
        switch( random(2) )
        {
        case 0:
                say( CYN "店小二笑咪咪地說道：這位" + RANK_D->query_respect(ob)
                   + CYN + "，進來喝杯茶，歇歇腿吧。\n" NOR);
                break;
        case 1:
                say( CYN "店小二用脖子上的毛巾抹了抹手，說道：這位" + RANK_D->query_respect(ob)
                   + CYN + "，請進請進。\n" NOR);
                break;
        }
}


