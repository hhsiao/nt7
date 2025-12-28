#include <ansi.h>
int give_gift();
mixed *story = 
({
        "上帝：摩西，當年你出埃及的那本聖經在哪裡？",
        "摩西：啊，偉大的主，它一直在我的身邊。",
        "上帝：恩，很好，你看現在人間自相殘殺，血腥迷漫，我想淨化他們。",
        "摩西：全能的主啊，應該怎麼辦呢？",
        "上帝：我想、把聖經交給他們，感化他們已經邪惡的心靈。",
        "摩西：喔，My God！",
        "上帝：有什麼不妥嗎？",
        "摩西：啊，沒有沒有……",
        "上帝：那就行了，趕快把聖經交給西洋傳教士吧。",
        "摩西：好的，我立刻就去。",
        "一本書從天上掉下來，隨後傳來一聲尖叫……",
        "摩西：天啊，我丟錯人了！Faint！！",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/task/story/bible", 1,
                           HIM "\n一本莎草紙的古老聖經掉到你的面前。\n\n" NOR);
        return 0;
}
