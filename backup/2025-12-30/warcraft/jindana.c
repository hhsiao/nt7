// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m小狗[2;37;0m[2;37;0m", ({"gougou"}));        
        set("gender", "女性");                
        set("long", "被Fuyuan砍去雙腿，練習直立行走的小狗。殘忍啊！[2;37;0m
它是金丹的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jindana");
        set("owner_name", "金丹");
        set_temp("owner", "jindana");
        set_temp("owner_name", "金丹");
        ::setup();
}
