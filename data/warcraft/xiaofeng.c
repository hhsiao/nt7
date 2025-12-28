// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m燕雲鐵騎[2;37;0m[2;37;0m[2;37;0m", ({"yanyun"}));        
        set("gender", "女性");                
        set("long", "燕雲18鐵騎，踏平一切奸侫[2;37;0m
它是蕭峰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaofeng");
        set("owner_name", "蕭峰");
        set_temp("owner", "xiaofeng");
        set_temp("owner_name", "蕭峰");
        ::setup();
}
