// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m不敗玄武[2;37;0m[2;37;0m", ({"choufengs"}));        
        set("gender", "女性");                
        set("long", "不敗玄武[2;37;0m
它是抽風的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "choufeng");
        set("owner_name", "抽風");
        set_temp("owner", "choufeng");
        set_temp("owner_name", "抽風");
        ::setup();
}
