#include <ansi.h>
int give_gift();
mixed *story =
({
    "【泥潭福利公告】王者歸來福利彩票正式發行！",
    "【泥潭福利公告】由冼老闆全權代理彩票發行及兌獎。",
    "…………",
    "冼老闆：為紀念雄霸天下……現在正式發行彩票……",
    "嘈雜聲：“快擠啊，聽說前幾號的中獎機會大啊”……",
    "“大家排隊，這不是93年發行股票認購證，這是福利彩票啊，你看你，",
    "話沒說完就把那個小孩推到了，你這是什麼愛心啊？那邊那個，你！啊",
    "要懂得禮讓嘛！唉……”",
    "一張彩票從冼老闆的手指縫裡掉了出來。誰都沒有注意。",
    "……好不容易完成了一天的工作……",
    "“恩？怎麼少了一張？好象被擠掉了！Faint！”",
    (: give_gift :)
});

void create() {
    seteuid(getuid());
}

mixed query_story_message(int step) {
    return step < sizeof(story) ? story[step] : 0;
}

int give_gift() {
    STORY_D->give_gift("/task/story/lottery", 1,
        HIM "\n一張 彩票 飄到你的面前。\n\n" NOR);
    return 0;
}
