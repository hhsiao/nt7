// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m神馬[2;37;0m[2;37;0m", ({"shenma"}));        
        set("gender", "女性");                
        set("long", "神馬...[2;37;0m
它是章子怡的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zhang");
        set("owner_name", "章子怡");
        set_temp("owner", "zhang");
        set_temp("owner_name", "章子怡");
        ::setup();
}
