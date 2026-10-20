module DateTime;

// don't actually create an idiomatic wrapper for this -
// use it privately to convert your language-native DateTime representation

@nodispose
opaque Handle {
    string toISO8601();
}
@useparenttype
opaque Owned extends Handle;

Owned createFromISO8601(string text);
