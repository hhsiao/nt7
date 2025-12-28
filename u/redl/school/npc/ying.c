// This program is a part of NITAN MudLIB 
// redl 2013/8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(NOR "殷葉" NOR, ({ "ying ye", "ying" }));
                set("nickname", CYN "清潔大媽" NOR);
        set("long", @LONG
這是一個在學校裡掃地的大媽，牙尖嘴利，口味頗重。
LONG);
        set("gender", "男性" );
        set("age", 36);
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
        set("per", 13);
        set("combat_exp", 1333000);

        set("inquiry", ([
                "入學" : "問我一個掃地的幹嘛？你到教室裡直接付錢給老師就行。\n"+NOR,
                "注音" : "對，何止我的姓是錯的注音，我整個姓名都是猥瑣的諧音。\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}




