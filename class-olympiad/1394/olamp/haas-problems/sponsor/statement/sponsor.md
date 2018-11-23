{% block title %}
اسپانسر!
(SPONSOR)
{% endblock %}

{% block _time_limit %}1{% endblock %}
{% block _memory_limit %}256{% endblock %}

{% block _contest %}دوره تابستان المپیاد کامپیوتر ۱۳۹۳

روز ۱۹{% endblock %}

{% block story %}
$n$ نقطه‌‌ی رنگی در صفحه وجود دارد. هر نقطه به یکی از رنگ‌های $1$ تا $m$ رنگ شده‌است. به ازای هر رنگ، حداکثر یکی از نقطه‌های آن رنگ را حذف کنید که فاصله‌ی منهتن دو نزدیک‌ترین نقطه بیشینه شود.
{% endblock %}

{% block input_format %}
در خط اول ورودی دو عدد $n$ و $m$ آمده‌است. در هر یک از $n$ خط بعد به ترتیب سه عدد $x$ و $y$ و $c$ آمده‌است.

+ $1 \le n \le 1392$

+ $1 \le m \le n/2$

+ $-10^6 \le x, y \le 10^6$

+ $1 \le c \le m$

+ مختصات همه‌ی نقطه‌ها متمایز است.

+ به ازای هر رنگ، حداقل دو نقطه به آن رنگ وجود دارد.

{% endblock %}

{% block output_format %}
در تنها خط خروجی، بیشینه‌ی فاصله‌ی دو نزدیک‌ترین نقطه را چاپ کنید.
{% endblock %}

{% block _sample_input_1 %}
6 2
0 0 1
1 1 2
1 0 1
2 1 2
2 0 1
3 1 2
{% endblock %}

{% block _sample_output_1 %}
2
{% endblock %}

{% block notes %}{% endblock %}
