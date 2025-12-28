// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武獸[2;37;0m[2;37;0m", ({"xuanwushou"}));        
        set("gender", "女性");                
        set("long", "防禦坐騎[2;37;0m
它是張波的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "zhangbo");
        set("owner_name", "張波");
        set_temp("owner", "zhangbo");
        set_temp("owner_name", "張波");
        ::setup();
}
