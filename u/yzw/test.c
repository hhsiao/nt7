

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("溼勇性", ({ "shi yongxing", "yongxing", "shi"}));
        set("age", 50);
        set("gender", "男性");
        set("long", "這是一個純潔的老和尚。\n");
        set("attitude", "peaceful");
        set("str", 100);
        set("dex", 100);
        set("combat_exp", 800000000000);
        set("shen_type", 1);

        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say(CYN "這位施主，你需要開光嗎？\n" NOR);
}

int accept_object(object who, object ob)
{
        if( query("money_id", ob) )
        {
                message_vision(CYN "$N" CYN "對$n" CYN "說道：你想開光" NOR +
                               HIY "(goto)" NOR + CYN "什麼部位？先告訴老衲我再付"
                               "錢也不遲。\n" NOR, this_object(), who);
                return 0;
        }

        return 0;
}

