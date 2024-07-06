"use client";
import GSearch from "@/components/gsearch";
import { useEffect, useState } from "react";

export default function Home() {
  const [searchText, setSearchText] = useState("");
  const [iframeUrl, setIframeUrl] = useState("");

  const handleSearch = () => {
    console.log(searchText);
    const edited = searchText.replace(" ", "+");
    setIframeUrl(edited);
  };

  useEffect(() => {
    const scriptCode = `
      function onLinkClick(url) {
        alert('URL from iframe: ' + url);
      }
    `;

    const script = document.createElement("script");
    script.innerHTML = scriptCode;
    document.body.appendChild(script);
  }, []);

  return (
    <div className="h-dvh w-dvw">
      {iframeUrl.length > 0 ? (
        <div className="absolute flex gap-3 justify-center pt-5 pl-52  bg-[#202124] w-full">
          <div className="relative">
            <input
              type="text"
              className="p-5 pl-12 h-[54px] rounded-3xl w-[690px] focus:border-none"
              value={searchText}
              onChange={(e) => setSearchText(e.target.value)}
              onKeyDown={(e) => {
                if (e.key === "Enter") {
                  handleSearch();
                }
              }}
            />
            <div className="absolute inset-y-0 left-0 pl-4 flex items-center">
              <svg
                xmlns="http://www.w3.org/2000/svg"
                className="h-5 w-5 text-gray-500"
                viewBox="0 0 20 20"
                fill="currentColor"
              >
                <path
                  fillRule="evenodd"
                  d="M8 4a4 4 0 100 8 4 4 0 000-8zM2 8a6 6 0 1110.89 3.476l4.817 4.817a1 1 0 01-1.414 1.414l-4.816-4.816A6 6 0 012 8z"
                  clipRule="evenodd"
                />
              </svg>
            </div>
          </div>
          <button
            className="bg-blue-500 text-white rounded-md p-2"
            onClick={handleSearch}
          >
            Search
          </button>
          <div className="absolute bottom-0 top-0 left-0 right-0 translate-x-[50%] translate-y-[50%] size-full">
            <h1 className="text-2xl font-bold">Google Search</h1>
          </div>
        </div>
      ) : (
        <div className="absolute flex gap-3 justify-center items-center size-full">
          <div className="relative -translate-y-[82px]">
            <input
              type="text"
              className="p-5 pl-12 max-h-[44px] rounded-3xl w-[584px] focus:border-none"
              value={searchText}
              onChange={(e) => setSearchText(e.target.value)}
              onKeyDown={(e) => {
                if (e.key === "Enter") {
                  handleSearch();
                }
              }}
            />
            <div className="absolute inset-y-0 left-0 pl-4 flex items-center">
              <svg
                xmlns="http://www.w3.org/2000/svg"
                className="h-5 w-5 text-gray-500"
                viewBox="0 0 20 20"
                fill="currentColor"
              >
                <path
                  fillRule="evenodd"
                  d="M8 4a4 4 0 100 8 4 4 0 000-8zM2 8a6 6 0 1110.89 3.476l4.817 4.817a1 1 0 01-1.414 1.414l-4.816-4.816A6 6 0 012 8z"
                  clipRule="evenodd"
                />
              </svg>
            </div>
          </div>
        </div>
      )}

      <GSearch iframeUrl={iframeUrl} />
    </div>
  );
}
