// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m蒼井空[2;37;0m[2;37;0m", ({"cjk"}));        
        set("gender", "女性");                
        set("long", "東洋島國漂洋過海而來的美女童顏巨乳風姿綽約人見人愛花見花開[2;37;0m
它是周不通的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "butong");
        set("owner_name", "周不通");
        set_temp("owner", "butong");
        set_temp("owner_name", "周不通");
        ::setup();
}
