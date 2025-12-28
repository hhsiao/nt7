// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬小鳥[2;37;0m[2;37;0m", ({"zzjjll"}));        
        set("gender", "男性");                
        set("long", "小鳥飛[2;37;0m
它是小花花的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hmjhs");
        set("owner_name", "小花花");
        set_temp("owner", "hmjhs");
        set_temp("owner_name", "小花花");
        ::setup();
}
