I've recently been using [bokeh](https://bokeh.org/) to produce some charts for my team on a regular basis and I found it a remarkable tool for the job.  I particularly appreciate that it will serve web pages from my machine so that I can share the graphs without needing to install anything on my manager's machine. 

During this process I created a bokeh script with several command line options to specify which data should be shown over what time frame.  While running this over the course of a week or so, I struggled every morning (OK, I just searched my bash history) to remember the right set of command line options to get the data I wanted on the external-facing IP address on a fresh port.

I really wanted to have a self-contained script that would launch bokeh as part of its operation, rather than remembering which command line options I needed to specify. I found [this SO article](https://stackoverflow.com/questions/51802159/how-to-embed-a-bokeh-server-in-a-standalone) which got me part of the way there, but I really wanted to specify ip address and port automatically. 

Below we'll walk through my current solution, which is not perfect, but works for what I needed.  

## Command Line Args

Let's start with the user interface.  For this example, you'll just have one option for your graph and two options to pass to bokeh:

```python
def get_command_line_args():
    """ Read command line args, of course."""
    parser = argparse.ArgumentParser()
    parser.add_argument("-b", "--blue", action="store_true")
    parser.add_argument(
        "-e",
        "--external",
        action="store_true",
        help="serve on local ip address instead of localhost",
    )
    parser.add_argument("-p", "--port", default="5006", help="socket port")
    args = parser.parse_args()

    args.ip_addr = get_local_ip_addr(args.external)

    if args.blue:
        args.color = "blue"
    else:
        args.color = "red"
    return args
```

The function starts with the graph option, `-b` which changes the color of the line from red to blue. You will expand this out to be whatever options you need to pass to your script, or remove it if there are none.

The next option is `-e` which switches the bokeh server from `localhost` mode to serving the webpage on an externally facing IP address. This option is just a bool, but we need to provide bokeh with a full IP address to use. You'll see that code below.

Finally the `-p` option is allowed for specifying the starting port number for serving. There is some code to retry with an increasing port number if the starting one is already in use. Again, we'll see this in another section below.

Once you've read the command line args, you can do a little processing on them. Let's skip the `get_local_ip_addr()` call at the moment and jump straight to the `-b` option.  The code uses this `bool` to set a new value in `args` to indicate if the graph line should be `red` or `blue`. 

> **Note:** This could also be done 

## Get Local IP Address

;alskdjd

## Starting the Server

a;lkdsjf

## Running the I/O Loop

lkj

## Conclusion

;lskdj