// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m瓦爾基里[2;37;0m[2;37;0m", ({"valkyr"}));        
        set("gender", "女性");                
        set("long", "$HIW$這是一位身披閃亮盔甲，騎著駿馬在天空中飛行的少女戰士。[2;37;0m
它是螢火之光的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "haniceme");
        set("owner_name", "螢火之光");
        set_temp("owner", "haniceme");
        set_temp("owner_name", "螢火之光");
        ::setup();
}
