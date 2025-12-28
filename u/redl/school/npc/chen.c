// This program is a part of NITAN MudLIB 
// redl 2013/8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(NOR "陳肥" NOR, ({ "chen fei", "chen" }));
                set("nickname", CYN "看門大叔" NOR);
        set("long", @LONG
這是一個在學校裡看門的大叔，盡忠職守，謹慎無過。
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
                "入學" : "問我一個看門的幹嘛？你到教室裡直接付錢給老師就行。\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}




